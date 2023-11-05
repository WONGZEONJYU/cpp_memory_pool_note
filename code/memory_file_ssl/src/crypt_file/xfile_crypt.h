#ifndef XFILE_CRYPT_H
#define XFILE_CRYPT_H
#include <memory>
#include <string>

class XReadTask;
class XCryptTask;
class XWriteTask;

class XFileCrypt final
{
	XFileCrypt(const XFileCrypt&) = delete;
	XFileCrypt& operator=(const XFileCrypt&) = delete;
public:
	explicit XFileCrypt() = default;
	explicit XFileCrypt(std::string infile, std::string outfile,
		std::string passwd, bool is_encrpty = true);

	bool Init(std::string infile, std::string outfile,
		std::string passwd, bool is_encrpty = true);

	void Start();
	void Wait();
private:
	std::shared_ptr<XReadTask> rt_;
	std::shared_ptr<XCryptTask> ct_;
	std::shared_ptr<XWriteTask> wt_;
};

#endif
