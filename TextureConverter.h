#pragma once
#include<string>
#include<Windows.h>
#include"DirectXTex/DirectXTex.h"

class TextureConverter
{
public:
	TextureConverter();
	~TextureConverter();

	/// <summary>
	/// テクスチャをWICからDDSに変換する
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void ConverterTextureWICToDDS(const std::string& filePath);

	/// <summary>
	/// マルチバイト文字列をワイド文字列に変換
	/// </summary>
	/// <param name="mString"></param>
	/// <returns>マルチバイト文字列</returns>
	/// <returns>ワイド文字列</returns>
	static std::wstring ConvertMultiByteStringTowideString(const std::string& mString);

private:
	/// <summary>
	/// テクスチャファイル読み込み
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void LoadWICTextureFromFile(const std::string& filePath);
	/// <summary>
	/// フォルダパスとファイル名を分解
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void SeparateFilePath(const std::wstring& filePath);

	/// <summary>
	/// DDSテクスチャとして書き出し
	/// </summary>
	void SaveDDSTextureToFile();

	DirectX::TexMetadata metaData_;
	DirectX::ScratchImage scratchImage_;

	//ディレクトリパス
	std::wstring directoryPath_;
	//ファイル名
	std::wstring fileName_;
	//ファイル拡張子
	std::wstring fileExt_;

};

