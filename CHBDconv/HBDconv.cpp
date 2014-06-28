// HBDconv.cpp: implementation of the CHBDconv class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HBDconv.h"
#include <cmath>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CString CHBDconv::BIN2HEX(CString sBIN_INPUT)  //二进制转十六进制
{ 
	INT iI;
	INT intLen;
	INT NumBlocks;
	CString chkbin;
	CString FullBin;
	CString TempBin;
	CString TempHex;
	CString sHEX_OUTPUT("");

	intLen=sBIN_INPUT.GetLength();  //获取字符串长度

		//如果长度小于4
	if (intLen<4)
	{   FullBin=sBIN_INPUT;
		if (intLen==3)
		{ FullBin= "0"+FullBin;}
		if (intLen==2)
		{ FullBin= "00"+FullBin;}
		if (intLen==1)
		{ FullBin= "000"+FullBin;}
		NumBlocks=1;
	}


	//如果长度等于4
	if (intLen==4)
	{	
		FullBin=sBIN_INPUT;
		NumBlocks=1;
	}


	//如果长度大于4
	if (intLen>4 )
	{
		FullBin=sBIN_INPUT;
		float TempDiv;
		float templen;
		CString stemp;

		templen = (float) sBIN_INPUT.GetLength();
		TempDiv = (templen/4);
		stemp.Format("%f",TempDiv);   //将除的结果浮点数转换为字符串
		if ( stemp.Mid(2,2)=="00" )
		{
			NumBlocks=(int)TempDiv;}         //强制 浮点转换到整型，有点牵强
			if ( stemp.Mid(2,2)=="25" )
			{
				FullBin="000"+FullBin;
				NumBlocks=(int)(FullBin.GetLength()/4); //强制 浮点转换到整型，有点牵强
			}
			if ( stemp.Mid(2,2)=="50" )
			{
				FullBin="00"+FullBin;
				NumBlocks=(int)(FullBin.GetLength()/4); //强制 浮点转换到整型，有点牵强
			}
			if ( stemp.Mid(2,2)=="75" )
			{
				FullBin="0"+FullBin;
				NumBlocks=(int)(FullBin.GetLength()/4); //强制 浮点转换到整型，有点牵强
			}

		}

	for (iI=0;iI!=NumBlocks;++iI)     //查表法转换16进制
		{
			TempBin=FullBin.Mid(iI*4,4);
				if (TempBin == "0000" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "0"; }
				if (TempBin == "0001" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "1"; }
				if (TempBin == "0010" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "2"; }
				if (TempBin == "0011" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "3"; }
				if (TempBin == "0100" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "4"; }
				if (TempBin == "0101" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "5"; }
				if (TempBin == "0110" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "6"; }
				if (TempBin == "0111" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "7"; }
				if (TempBin == "1000" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "8"; }
				if (TempBin == "1001" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "9"; }
				if (TempBin == "1010" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "A"; }
				if (TempBin == "1011" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "B"; }
				if (TempBin == "1100" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "C"; }
				if (TempBin == "1101" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "D"; }
				if (TempBin == "1110" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "E"; }
				if (TempBin == "1111" )
				{	sHEX_OUTPUT = sHEX_OUTPUT + "F"; }
		}
	sHEX_OUTPUT.TrimLeft("0");
	if(sHEX_OUTPUT.IsEmpty())
	{
		return "0";
	}
	else
	{
		return sHEX_OUTPUT;
	}

}

CString CHBDconv::HEX2BIN(CString sHEX_INPUT)  //十六进制转换为二进制
{   
	
	INT iI;
	INT intLen;
	CString sBIN_OUTPUT("");

	sHEX_INPUT.MakeUpper();  //将输入转换为大写
	intLen=sHEX_INPUT.GetLength();  //获取字符串长度


	for (iI=0; iI!=intLen; ++iI) //查表法组合为二进制
	{
		if (sHEX_INPUT[iI]=='0')
			sBIN_OUTPUT=sBIN_OUTPUT+"0000";
		else if (sHEX_INPUT[iI]=='1')
			sBIN_OUTPUT=sBIN_OUTPUT+"0001";
		else if (sHEX_INPUT[iI]=='2')
			sBIN_OUTPUT=sBIN_OUTPUT+"0010";
		else if (sHEX_INPUT[iI]=='3')
			sBIN_OUTPUT=sBIN_OUTPUT+"0011";
		else if (sHEX_INPUT[iI]=='4')
			sBIN_OUTPUT=sBIN_OUTPUT+"0100";
		else if (sHEX_INPUT[iI]=='5')
			sBIN_OUTPUT=sBIN_OUTPUT+"0101";
		else if(sHEX_INPUT[iI]=='6')
			sBIN_OUTPUT=sBIN_OUTPUT+"0110";
		else if(sHEX_INPUT[iI]=='7')
			sBIN_OUTPUT=sBIN_OUTPUT+"0111";
		else if (sHEX_INPUT[iI]=='8')
			sBIN_OUTPUT=sBIN_OUTPUT+"1000";
		else if (sHEX_INPUT[iI]=='9')
			sBIN_OUTPUT=sBIN_OUTPUT+"1001";
		else if (sHEX_INPUT[iI]=='A')
			sBIN_OUTPUT=sBIN_OUTPUT+"1010";
		else if (sHEX_INPUT[iI]=='B')
			sBIN_OUTPUT=sBIN_OUTPUT+"1011";
		else if (sHEX_INPUT[iI]=='C')
			sBIN_OUTPUT=sBIN_OUTPUT+"1100";
		else if (sHEX_INPUT[iI]=='D')
			sBIN_OUTPUT=sBIN_OUTPUT+"1101";
		else if (sHEX_INPUT[iI]=='E')
			sBIN_OUTPUT=sBIN_OUTPUT+"1110";
		else if (sHEX_INPUT[iI]=='F')
			sBIN_OUTPUT=sBIN_OUTPUT+"1111";
	}	
	sBIN_OUTPUT.TrimLeft("0");     //消除左边的“0”
	if(sBIN_OUTPUT.IsEmpty())
	{
		return "0";
	}
	else
	{
		return sBIN_OUTPUT;
	}
}

CString CHBDconv::DEC2BIN(CString sDEC_INPUT) // 十进制转化为二进制
{ 
	CString sBIN_OUTPUT(""), sTmp("");
	unsigned int iNumerartor = (unsigned int)atof(sDEC_INPUT); // 将自字符串字面值转化为整形，注意INT型的最大值
	int iQuotient(0), iRemainder(0); //商，余数
	bool bStop(TRUE);
	//将数除以2，每次的余数保留排列
	while(bStop)
	{
		iQuotient = iNumerartor/2;
		iRemainder = iNumerartor%2;
		sTmp.Format("%d",iRemainder); //将余数保留
		sBIN_OUTPUT += sTmp;
		iNumerartor = iQuotient; // 把商赋给被除数
		if (iQuotient == 0)
		{
			bStop = FALSE;
		}
	}
	sBIN_OUTPUT.MakeReverse(); //翻转字符串顺序
	sBIN_OUTPUT.TrimLeft("0");
	if(sBIN_OUTPUT.IsEmpty())
	{
		return "0";
	}
	else
	{
		return sBIN_OUTPUT;
	}

}

// CString CHBDconv::BIN2DEC(CString sBIN_INPUT) // 二进制转化为十进制
// { 
// 	//要从右到左用二进制的每个数去乘以2的相应次方
// 	CString sDEC_OUTPUT("");
// 	sBIN_INPUT.MakeReverse();
// 	double nTmp(0);
// 
// 	for(int i=0; i!=sBIN_INPUT.GetLength(); ++i)
// 	{
// 		nTmp += atoi(sBIN_INPUT.Mid(i,1)) * pow(2.0,i); //注意pow()重载的问题
// 	}
// 
// 	sDEC_OUTPUT.Format("%.0f",nTmp); 
// 	sDEC_OUTPUT.TrimLeft("0");
// 
// 	if(sDEC_OUTPUT.IsEmpty())
// 	{
// 		return "0";
// 	}
// 	else
// 	{
// 		return sDEC_OUTPUT;
// 	}
// 	
// }

bool CHBDconv::Bin2Dec(CString sBin_Input, CString &sDec_Output, bool bSigned )
{  
	//////////////////////////////////////////////////////////////////////////
	//
	// 将 二进制字面字符串 转换为 十进制字面字符串 
	//
	// bSigned 为 true 时，为带符号十进制，范围[-2147483648，2147483647]，默认
	// bSigned 为 false 时，为无符号十进制，范围[0,4294967295], 可选
	//
	// 返回 true ，转换成功，暂未实现
	// 返回 false ，转换失败，暂未实现
	//
	//////////////////////////////////////////////////////////////////////////

	const int nBits = 32; // 32位，有效位数
	const double nMax = pow(2.0,nBits-1);   // 2147483648)
	double ResultSigned(0.0);
	double ResultUnsigned(0.0);

	//如果位数超出， 返回 false
	if (sBin_Input.GetLength() > nBits )  
	{ 
		sDec_Output.Empty();
		return false;
	}

	//如果不是 0 或者 1 ，返回 false
	for (int i=0;i!=sBin_Input.GetLength();++i) 
	{

		if (!(sBin_Input.Mid(i,1) == "0" || sBin_Input.Mid(i,1) =="1"))
			return false;

	}

	if ( bSigned) //有符号数
	{		
		if (sBin_Input.GetLength()==nBits && sBin_Input.Mid(0,1) =="1" )  // nBits = 32位有符号数
		{ 			
			sBin_Input.Delete(0,1);  //将符号位剔除	
			sBin_Input.MakeReverse();			
			for(int i=0; i!=sBin_Input.GetLength();++i)
			{
				ResultSigned += atoi(sBin_Input.Mid(i,1))*pow(2.0,i);
			}
			ResultSigned = nMax - ResultSigned;
			sDec_Output.Format("%.0f",ResultSigned);
			sDec_Output = "-" + sDec_Output;
		}else //没有符号位
		{
			sBin_Input.MakeReverse();
			for(int i=0; i!=sBin_Input.GetLength();++i)
			{
				ResultSigned += atoi(sBin_Input.Mid(i,1))*pow(2.0,i);
			}
			sDec_Output.Format("%.0f",ResultSigned);
		}

	}else       //无符号数
	{
		sBin_Input.MakeReverse();		
		for(int i=0; i!=sBin_Input.GetLength();++i)
		{
			ResultUnsigned += atoi(sBin_Input.Mid(i,1))*pow(2.0,i);
		}
		sDec_Output.Format("%.0f",ResultUnsigned);
	}

	
 	return true;

}



