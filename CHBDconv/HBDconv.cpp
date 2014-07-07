// HBDconv.cpp: implementation of the CHBDconv class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HBDconv.h"
#include <CCTYPE>
#include <CMATH>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

bool CHBDconv::Bin2Hex(CString sBin_Input, CString &sHex_Output)
{
	//////////////////////////////////////////////////////////////////////////
	//
	// 将 二进制字面字符串 转换为 十六进制字面字符串 
	//
	// 限制二进制输入为 32 位
	//
	// 返回 true ，转换成功
	// 返回 false ，转换失败
	//
	//////////////////////////////////////////////////////////////////////////

	INT iI;
	INT intLen;
	INT NumBlocks;
	const int nBits=32;
	CString chkbin;
	CString FullBin;
	CString TempBin;
	CString TempHex;

	//如果位数超出， 返回 false
	if (sBin_Input.GetLength() > nBits )  // nBits 定为32 位
	{ 
		sHex_Output.Empty();
		return false;
	}

	//如果不是 0 或者 1 ，返回 false
	for (int i=0;i!=sBin_Input.GetLength();++i) 
	{
		
		if (!(sBin_Input.Mid(i,1) == "0" || sBin_Input.Mid(i,1) =="1"))
		{
			sHex_Output.Empty();
			return false;
		}
		
	}

	sHex_Output.Empty();
	intLen=sBin_Input.GetLength();  //获取字符串长度

	//如果长度小于4
	if (intLen<4)
	{   FullBin=sBin_Input;
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
		FullBin=sBin_Input;
		NumBlocks=1;
	}


	//如果长度大于4
	if (intLen>4 )
	{
		FullBin=sBin_Input;
		float TempDiv;
		float templen;
		CString stemp;

		templen = (float) sBin_Input.GetLength();
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
				{	sHex_Output = sHex_Output + "0"; }
				if (TempBin == "0001" )
				{	sHex_Output = sHex_Output + "1"; }
				if (TempBin == "0010" )
				{	sHex_Output = sHex_Output + "2"; }
				if (TempBin == "0011" )
				{	sHex_Output = sHex_Output + "3"; }
				if (TempBin == "0100" )
				{	sHex_Output = sHex_Output + "4"; }
				if (TempBin == "0101" )
				{	sHex_Output = sHex_Output + "5"; }
				if (TempBin == "0110" )
				{	sHex_Output = sHex_Output + "6"; }
				if (TempBin == "0111" )
				{	sHex_Output = sHex_Output + "7"; }
				if (TempBin == "1000" )
				{	sHex_Output = sHex_Output + "8"; }
				if (TempBin == "1001" )
				{	sHex_Output = sHex_Output + "9"; }
				if (TempBin == "1010" )
				{	sHex_Output = sHex_Output + "A"; }
				if (TempBin == "1011" )
				{	sHex_Output = sHex_Output + "B"; }
				if (TempBin == "1100" )
				{	sHex_Output = sHex_Output + "C"; }
				if (TempBin == "1101" )
				{	sHex_Output = sHex_Output + "D"; }
				if (TempBin == "1110" )
				{	sHex_Output = sHex_Output + "E"; }
				if (TempBin == "1111" )
				{	sHex_Output = sHex_Output + "F"; }
		}
	sHex_Output.TrimLeft("0");
	if (sHex_Output.IsEmpty())
		sHex_Output = "0";

	return true;
}


bool CHBDconv::Hex2Bin(CString sHex_Input, CString &sBin_Output)
{
	//////////////////////////////////////////////////////////////////////////
	//
	// 将 十六进制字面字符串 转换为 二进制字面字符串 
	//
	// 限制十六进制输入为 8 位
	//
	// 返回 true ，转换成功
	// 返回 false ，转换失败
	//
	//////////////////////////////////////////////////////////////////////////
	const int nBits = 32;
	
	sBin_Output.Empty();	
	sHex_Input.MakeUpper();  //将输入转换为大写

	//如果位数超出， 返回 false
	if (sHex_Input.GetLength() > nBits/4 )  // nBits 定为32 位
	{ 
		sBin_Output.Empty();
		return false;
	}	
		
	////判断输入是否为十六进制，不是返回false
	for (int i=0;i!=sHex_Input.GetLength();++i) 
	{
		
		if  (! ('0' <= sHex_Input.GetAt(i) && sHex_Input.GetAt(i) <= '9' ||
				'a' <= sHex_Input.GetAt(i) && sHex_Input.GetAt(i) <= 'f' ||
				'A' <= sHex_Input.GetAt(i) && sHex_Input.GetAt(i) <= 'F')
			)
		{
			sBin_Output.Empty();
			return false;
		}
	}
	

	for ( i=0; i!=sHex_Input.GetLength(); ++i) //查表法组合为二进制
	{
		if (sHex_Input[i]=='0')
			sBin_Output=sBin_Output+"0000";
		else if (sHex_Input[i]=='1')
			sBin_Output=sBin_Output+"0001";
		else if (sHex_Input[i]=='2')
			sBin_Output=sBin_Output+"0010";
		else if (sHex_Input[i]=='3')
			sBin_Output=sBin_Output+"0011";
		else if (sHex_Input[i]=='4')
			sBin_Output=sBin_Output+"0100";
		else if (sHex_Input[i]=='5')
			sBin_Output=sBin_Output+"0101";
		else if(sHex_Input[i]=='6')
			sBin_Output=sBin_Output+"0110";
		else if(sHex_Input[i]=='7')
			sBin_Output=sBin_Output+"0111";
		else if (sHex_Input[i]=='8')
			sBin_Output=sBin_Output+"1000";
		else if (sHex_Input[i]=='9')
			sBin_Output=sBin_Output+"1001";
		else if (sHex_Input[i]=='A')
			sBin_Output=sBin_Output+"1010";
		else if (sHex_Input[i]=='B')
			sBin_Output=sBin_Output+"1011";
		else if (sHex_Input[i]=='C')
			sBin_Output=sBin_Output+"1100";
		else if (sHex_Input[i]=='D')
			sBin_Output=sBin_Output+"1101";
		else if (sHex_Input[i]=='E')
			sBin_Output=sBin_Output+"1110";
		else if (sHex_Input[i]=='F')
			sBin_Output=sBin_Output+"1111";
	}	
	sBin_Output.TrimLeft("0");     //消除多余的“0”
	if (sBin_Output.IsEmpty())
		sBin_Output ="0";

	return true;
}

bool CHBDconv::Dec2Bin(CString sDec_Input, CString &sBin_Output, bool bSigned)
{
	//////////////////////////////////////////////////////////////////////////
	//
	// 将 十进制字面字符串 转换为 二进制字面字符串 
	//
	// bSigned 为 true 时，为带符号十进制，范围[-2147483648，2147483647]，默认
	// bSigned 为 false 时，为无符号十进制，范围[0,4294967295], 可选
	//
	// 返回 true ，转换成功
	// 返回 false ，转换失败
	//
	//////////////////////////////////////////////////////////////////////////

	const int nBits = 32; // 32位，有效位数
	const double nMin = 0 - pow(2.0,nBits-1); //   符号数最小  [-2147483648
	const double nMax = pow(2.0,nBits-1) ;    //   符号数最大   2147483648)
	const double nMaxU = 2*pow(2.0,nBits-1)-1;  // 无符号数最大  4294967295]

	//如果不是数字 0~9 和 负号 -，返回false
	for (int i=0; i!=sDec_Input.GetLength();++i)
	{
		if (!( isdigit(sDec_Input[i]) || sDec_Input.Mid(i,1) == "-"))
		{
			sBin_Output.Empty();
			return false;
		}

	}

	if (bSigned) // 有符号数
	{
		//超出数值范围 [-2147483648，2147483647] ，返回 false  
		if( !( nMin<= atof(sDec_Input) && atof(sDec_Input) < nMax  ) )
		{
			sBin_Output.Empty();		
			return false;
		}

	}else  // 无符号数
	{
		//超出数值范围 [0，4294967295] ，返回 false  
		if( !( 0 <= atof(sDec_Input) && atof(sDec_Input) <= nMaxU ) )
		{
			sBin_Output.Empty();		
			return false;
		}
		//如果第一个字符是 “-”，返回false
		if (sDec_Input.Mid(0,1) == "-" )
		{
			sBin_Output.Empty();		
			return false;
		}
	}

	if (!bSigned) ///////////////////////////////////非符号数///////////////////////////////////////	 
	{
		unsigned int iNumerartor = (unsigned int)atof(sDec_Input); // 将自字符串字面值转化为整形，注意INT型的最大值
		int iQuotient(0), iRemainder(0); //商，余数
		bool bStop(TRUE);
		CString sTmp;
		sBin_Output.Empty();
		//将数除以2，每次的余数保留排列
		while(bStop)
		{			
			iQuotient = iNumerartor/2;
			iRemainder = iNumerartor%2;
			sTmp.Format("%d",iRemainder); //将余数保留
			sBin_Output += sTmp;
			iNumerartor = iQuotient; // 把商赋给被除数
			if (iQuotient == 0)
			{
				bStop = FALSE;
			}
	 	}
	 	sBin_Output.MakeReverse(); //翻转字符串顺序

	}else //////////////////////////////////  符号数  ////////////////////////////////////////
	{
		//有负号 “-”
		if (sDec_Input.Mid(0,1) == "-" )
		{
			sDec_Input.Delete(0,1); //将“-”剔除
			sDec_Input.TrimLeft("0");

			if (!(sDec_Input.IsEmpty())) // 如果不为空
			{
				
				unsigned int iNumerartor = (int) nMax - (unsigned int)atof(sDec_Input); // 将自字符串字面值转化为整形，注意INT型的最大值
				int iQuotient(0), iRemainder(0); //商，余数
				bool bStop(TRUE);
				CString sTmp;
				sBin_Output.Empty();
				//将数除以2，每次的余数保留排列
				while(bStop)
				{			
					iQuotient = iNumerartor/2;
					iRemainder = iNumerartor%2;
					sTmp.Format("%d",iRemainder); //将余数保留
					sBin_Output += sTmp;
					iNumerartor = iQuotient; // 把商赋给被除数
					if (iQuotient == 0)
					{
						bStop = FALSE;
					}
				}
				int nZero = nBits - sBin_Output.GetLength() -1 ; //需要补0的个数
				for (int i=0;i!=nZero;++i)
				{
					sBin_Output = sBin_Output + "0";
				}
				sBin_Output = sBin_Output + "1" ;
				sBin_Output.MakeReverse(); //翻转字符串顺序

			}
			else
			{
				sBin_Output="0";
			}			
			
		}
		else // 无负号 “-”
		{
			unsigned int iNumerartor = (unsigned int)atof(sDec_Input); // 将自字符串字面值转化为整形，注意INT型的最大值
			int iQuotient(0), iRemainder(0); //商，余数
			bool bStop(TRUE);
			CString sTmp;
			sBin_Output.Empty();
			//将数除以2，每次的余数保留排列
			while(bStop)
			{			
				iQuotient = iNumerartor/2;
				iRemainder = iNumerartor%2;
				sTmp.Format("%d",iRemainder); //将余数保留
				sBin_Output += sTmp;
				iNumerartor = iQuotient;  // 把商赋给被除数
				if (iQuotient == 0)
				{
					bStop = FALSE;
				}
			}
			sBin_Output.MakeReverse(); // 翻转字符串顺序
		}		
	}

	return true;
}

bool CHBDconv::Bin2Dec(CString sBin_Input, CString &sDec_Output, bool bSigned)
{  
	//////////////////////////////////////////////////////////////////////////
	//
	// 将 二进制字面字符串 转换为 十进制字面字符串 
	//
	// bSigned 为 true 时，为带符号十进制，范围[-2147483648，2147483647]，默认
	// bSigned 为 false 时，为无符号十进制，范围[0,4294967295], 可选
	//
	// 返回 true ，转换成功
	// 返回 false ，转换失败
	//
	//////////////////////////////////////////////////////////////////////////

	const int nBits = 32; // 32位，有效位数
	const double nMax = pow(2.0,nBits-1);   // 2147483648)
	double ResultSigned(0.0);
	double ResultUnsigned(0.0);

	//如果位数超出， 返回 false
	if (sBin_Input.GetLength() > nBits )  // nBits 定为32 位
	{ 
		sDec_Output.Empty();
		return false;
	}

	//如果不是 0 或者 1 ，返回 false
	for (int i=0;i!=sBin_Input.GetLength();++i) 
	{

		if (!(sBin_Input.Mid(i,1) == "0" || sBin_Input.Mid(i,1) =="1"))
		{
			sDec_Output.Empty();
			return false;
		}

	}

	if ( bSigned) //有符号数
	{		
		if (sBin_Input.GetLength()==nBits && sBin_Input.Mid(0,1) =="1" )  // 有符号位
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


bool CHBDconv::Hex2Dec(CString sHex_Input, CString &sDec_Output, bool bSigned)
{

	//////////////////////////////////////////////////////////////////////////
	//
	// 将 十六进制字面字符串 转换为 十进制字面字符串
	// 
	// 限制十六进制输入为 8 位
	//
	// 返回 true ，转换成功
	// 返回 false ，转换失败
	//
	//////////////////////////////////////////////////////////////////////////

	CString sTmp;
	if ( Hex2Bin(sHex_Input,sTmp) )
	{
		if ( Bin2Dec(sTmp,sDec_Output,bSigned))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	
}

bool CHBDconv::Dec2Hex(CString sDec_Input, CString &sHex_Output, bool bSigned )
{
	//////////////////////////////////////////////////////////////////////////
	//
	// 将 十进制字面字符串 转换为 十六进制字面字符串
	// 
	// bSigned 为 true 时，为带符号十进制，范围[-2147483648，2147483647]，默认
	// bSigned 为 false 时，为无符号十进制，范围[0,4294967295], 可选
	//
	// 返回 true ，转换成功
	// 返回 false ，转换失败
	//
	//////////////////////////////////////////////////////////////////////////

	CString sTmp;
	if (Dec2Bin(sDec_Input,sTmp,bSigned))
	{
		if (Bin2Hex(sTmp,sHex_Output))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}


