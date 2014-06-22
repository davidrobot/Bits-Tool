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

CHBDconv::CHBDconv()
{

}

CHBDconv::~CHBDconv()
{

}

CString CHBDconv::BIN2HEX(CString sBIN_INPUT)  //������תʮ������
{ 
	INT iI;
	INT intLen;
	INT NumBlocks;
	CString chkbin;
	CString FullBin;
	CString TempBin;
	CString TempHex;
	CString sHEX_OUTPUT;
	bool bBIN;

	sHEX_OUTPUT.Empty(); //������ַ������	
	intLen=sBIN_INPUT.GetLength();  //��ȡ�ַ�������

 	for (iI=0;iI<intLen;iI++) //����ж��Ƿ��Ƕ�����
	{	if ( sBIN_INPUT[iI]!='1' && sBIN_INPUT[iI]!='0')
		{	bBIN=FALSE;
 			AfxMessageBox(_T("����Ƕ����ƣ�"));
 			break;
 		}
		else
		{ bBIN=TRUE;
		}
	}

	if (bBIN)      //����Ƕ����ƣ����к�������
	{
		//�������С��4
		if (intLen<4)
		{   FullBin=sBIN_INPUT;
			if (intLen==3)
			{ FullBin= "0"+FullBin;}
			if (intLen==2)
			{ FullBin= "00"+FullBin;}
			if (intLen==1)
			{ FullBin= "000"+FullBin;}
			if (intLen==0)
			{ //AfxMessageBox(_T("û������"));  05.30.13 Changed : ȡ��BIN���������ʾ
			}

			NumBlocks=1;
		}


		//������ȵ���4
		if (intLen==4)
		{	
			FullBin=sBIN_INPUT;
			NumBlocks=1;
		}


		//������ȴ���4
		if (intLen>4 )
		{
			FullBin=sBIN_INPUT;

			float TempDiv;
			float templen;
			CString stemp;

			templen = (float) sBIN_INPUT.GetLength();
			TempDiv = (templen/4);
			stemp.Format("%f",TempDiv);   //�����Ľ��������ת��Ϊ�ַ���
			if ( stemp.Mid(2,2)=="00" )
			{
				NumBlocks=(int)TempDiv;}         //ǿ�� ����ת�������ͣ��е�ǣǿ
			if ( stemp.Mid(2,2)=="25" )
			{
				FullBin="000"+FullBin;
				NumBlocks=(int)(FullBin.GetLength()/4); //ǿ�� ����ת�������ͣ��е�ǣǿ
			}
			if ( stemp.Mid(2,2)=="50" )
			{
				FullBin="00"+FullBin;
				NumBlocks=(int)(FullBin.GetLength()/4); //ǿ�� ����ת�������ͣ��е�ǣǿ
			}
			if ( stemp.Mid(2,2)=="75" )
			{
				FullBin="0"+FullBin;
				NumBlocks=(int)(FullBin.GetLength()/4); //ǿ�� ����ת�������ͣ��е�ǣǿ
			}

		}

		for (iI=0;iI<NumBlocks;iI++)     //���ת��16����
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

	}
	return sHEX_OUTPUT;

}

CString CHBDconv::HEX2BIN(CString sHEX_INPUT)  //ʮ������ת��Ϊ������
{   
	
	INT iI;
	INT intLen;
	CString sBIN_OUTPUT;

	sHEX_INPUT.MakeUpper();  //������ת��Ϊ��д
	intLen=sHEX_INPUT.GetLength();  //��ȡ�ַ�������


	sBIN_OUTPUT.Empty(); //������ַ������


	for (iI=0; iI<intLen; iI++) //������Ϊ������
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
		else
		{	AfxMessageBox(_T("�����ʮ�����ƣ�"));}  
	}
	
	sBIN_OUTPUT.TrimLeft("0");     //������ߵġ�0��
	return sBIN_OUTPUT;
}

CString CHBDconv::DEC2BIN(CString sDEC_INPUT) // ʮ����ת��Ϊ������
{ 
	CString sBIN_OUTPUT(""), sTmp("");
	int iNumerartor = atoi(sDEC_INPUT); // �����ַ�������ֵת��Ϊ����
	int iQuotient(0), iRemainder(0); //�̣�����
	bool bStop(TRUE);
	//��������2��ÿ�ε�������������
	while(bStop)
	{
		iQuotient = iNumerartor/2;
		iRemainder = iNumerartor%2;
		sTmp.Format("%d",iRemainder); //����������
		sBIN_OUTPUT += sTmp;
		iNumerartor = iQuotient; // ���̸���������
		if (iQuotient == 0)
		{
			bStop = FALSE;
		}
	}
	sBIN_OUTPUT.MakeReverse(); //��ת�ַ���˳��
	return sBIN_OUTPUT;

}

CString CHBDconv::BIN2DEC(CString sBIN_INPUT) // ������ת��Ϊʮ����
{ 
	//Ҫ���ҵ����ö����Ƶ�ÿ����ȥ����2����Ӧ�η�
	CString sDEC_OUTPUT("");
	sBIN_INPUT.MakeReverse();
	double nTmp(0);

	for(int i=0; i!=sBIN_INPUT.GetLength(); ++i)
	{
		nTmp += atoi(sBIN_INPUT.Mid(i,1)) * pow(2.0,i);
	}

	sDEC_OUTPUT.Format("%.0f",nTmp); 
	sDEC_OUTPUT.TrimLeft("0");
	return sDEC_OUTPUT;
	
}

CString CHBDconv::DEC2HEX(CString sDEC_INPUT) //ʮ����->������->ʮ������
{
	return (BIN2HEX(DEC2BIN(sDEC_INPUT)));

}

CString CHBDconv::HEX2DEC(CString sHEX_INPUT) //ʮ������->������->ʮ����
{
	return (BIN2DEC(HEX2BIN(sHEX_INPUT)));
}

