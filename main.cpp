#include<cstdio>
#include<cstdlib>
#include <cassert>
#include<windows.h>

#include"TextureConverter.h"

enum Argument
{
	kApplicationPath,//アプリケーションのパス
	kFilePath,//渡されたファイルのパス
	NumArgument//要素数　一番最後で固定
};

int main(int argc,char*argv[])
{
	for (int i = 0; i < argc; i++)
	{
		assert(argc >= NumArgument);

		HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
		assert(SUCCEEDED(hr));

		TextureConverter converter;
		converter.ConverterTextureWICToDDS(argv[kFilePath]);

		CoUninitialize();
	}

	system("pause");
	return 0;
}