#ifndef THREAD_H_
#define THREAD_H_

#include <memory>
#include <type_traits>
#include <utility>

class Mythread
{

public:

    struct _State{
      virtual ~_State();
      virtual void _M_run() = 0;
    };

    using _State_ptr = std::unique_ptr<_State>;

    using __gthread_t = void*;

    void _M_start_thread(_State_ptr, void (*)());

    template<typename _Callable>
    struct _State_impl : public _State{

	    _Callable		_M_func;
	    _State_impl(_Callable&& __f) : _M_func(std::forward<_Callable>(__f)){ }

	    void _M_run() override{ 
            _M_func(); 
        }
    };

    template<typename _Callable>
    static _State_ptr _S_make_state(_Callable&& __f)
    {
	    using _Impl = _State_impl<_Callable>;
	    return _State_ptr{new _Impl{std::forward<_Callable>(__f)}};
    }

    template<typename _Callable, typename... _Args>
    explicit Mythread(_Callable&& __f, _Args&&... __args){
	    auto __depend = reinterpret_cast<void(*)()>(&pthread_create);
        _M_start_thread(_S_make_state( __make_invoker(std::forward<_Callable>(__f),std::forward<_Args>(__args)...)),__depend);
    }

    template<typename _Tuple>
    struct _Invoker
    {
	    _Tuple _M_t;

        template<typename>
        struct __result;

        template<typename _Fn, typename... _Args>
        struct __result<tuple<_Fn, _Args...>>: __invoke_result<_Fn, _Args...>{ };

        template<size_t... _Ind>
        typename __result<_Tuple>::type _M_invoke(_Index_tuple<_Ind...>)
        { 
            return std::__invoke(std::get<_Ind>(std::move(_M_t))...); 
        }

        typename __result<_Tuple>::type operator()() {
            using _Indices = typename _Build_index_tuple<tuple_size<_Tuple>::value>::__type;
            return _M_invoke(_Indices());
        }

    };

    template<typename... _Tp>
    using __decayed_tuple = tuple<typename decay<_Tp>::type...>;

    template<typename _Callable, typename... _Args>
    static _Invoker<__decayed_tuple<_Callable, _Args...>> __make_invoker(_Callable&& __callable, _Args&&... __args) {
        return { __decayed_tuple<_Callable, _Args...>{std::forward<_Callable>(__callable), std::forward<_Args>(__args)...} };
    }

};

