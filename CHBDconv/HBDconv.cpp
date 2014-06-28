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

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CString CHBDconv::BIN2HEX(CString sBIN_INPUT)  //������תʮ������
{ 
	INT iI;
	INT intLen;
	INT NumBlocks;
	CString chkbin;
	CString FullBin;
	CString TempBin;
	CString TempHex;
	CString sHEX_OUTPUT("");

	intLen=sBIN_INPUT.GetLength();  //��ȡ�ַ�������

		//�������С��4
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

	for (iI=0;iI!=NumBlocks;++iI)     //���ת��16����
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

CString CHBDconv::HEX2BIN(CString sHEX_INPUT)  //ʮ������ת��Ϊ������
{   
	
	INT iI;
	INT intLen;
	CString sBIN_OUTPUT("");

	sHEX_INPUT.MakeUpper();  //������ת��Ϊ��д
	intLen=sHEX_INPUT.GetLength();  //��ȡ�ַ�������


	for (iI=0; iI!=intLen; ++iI) //������Ϊ������
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
	sBIN_OUTPUT.TrimLeft("0");     //������ߵġ�0��
	if(sBIN_OUTPUT.IsEmpty())
	{
		return "0";
	}
	else
	{
		return sBIN_OUTPUT;
	}
}

// CString CHBDconv::DEC2BIN(CString sDEC_INPUT) // ʮ����ת��Ϊ������
// { 
// 	CString sBIN_OUTPUT(""), sTmp("");
// 	unsigned int iNumerartor = (unsigned int)atof(sDEC_INPUT); // �����ַ�������ֵת��Ϊ���Σ�ע��INT�͵����ֵ
// 	int iQuotient(0), iRemainder(0); //�̣�����
// 	bool bStop(TRUE);
// 	//��������2��ÿ�ε�������������
// 	while(bStop)
// 	{
// 		iQuotient = iNumerartor/2;
// 		iRemainder = iNumerartor%2;
// 		sTmp.Format("%d",iRemainder); //����������
// 		sBIN_OUTPUT += sTmp;
// 		iNumerartor = iQuotient; // ���̸���������
// 		if (iQuotient == 0)
// 		{
// 			bStop = FALSE;
// 		}
// 	}
// 	sBIN_OUTPUT.MakeReverse(); //��ת�ַ���˳��
// 	sBIN_OUTPUT.TrimLeft("0");
// 	if(sBIN_OUTPUT.IsEmpty())
// 	{
// 		return "0";
// 	}
// 	else
// 	{
// 		return sBIN_OUTPUT;
// 	}
// 
// }

bool CHBDconv::Dec2Bin(CString sDec_Input, CString &sBin_Output, bool bSigned)
{
	//////////////////////////////////////////////////////////////////////////
	//
	// �� ʮ���������ַ��� ת��Ϊ �����������ַ��� 
	//
	// bSigned Ϊ true ʱ��Ϊ������ʮ���ƣ���Χ[-2147483648��2147483647]��Ĭ��
	// bSigned Ϊ false ʱ��Ϊ�޷���ʮ���ƣ���Χ[0,4294967295], ��ѡ
	//
	// ���� true ��ת���ɹ�
	// ���� false ��ת��ʧ��
	//
	//////////////////////////////////////////////////////////////////////////

	const int nBits = 32; // 32λ����Чλ��
	const double nMin = 0 - pow(2.0,nBits-1); //   ��������С  [-2147483648
	const double nMax = pow(2.0,nBits-1) ;    //   ���������   2147483648)
	const double nMaxU = 2*pow(2.0,nBits-1)-1;  // �޷��������  4294967295]

	//����������� 0~9 �� ���� -������false
	for (int i=0; i!=sDec_Input.GetLength();++i)
	{
		if (!( isdigit(sDec_Input[i]) || sDec_Input.Mid(i,1) == "-"))
		{
			sBin_Output.Empty();
			return false;
		}

	}

	if (bSigned) // �з�����
	{
		//������ֵ��Χ [-2147483648��2147483647] ������ false  
		if( !( nMin<= atof(sDec_Input) && atof(sDec_Input) < nMax  ) )
		{
			sBin_Output.Empty();		
			return false;
		}

	}else  // �޷�����
	{
		//������ֵ��Χ [0��4294967295] ������ false  
		if( !( 0 <= atof(sDec_Input) && atof(sDec_Input) <= nMaxU ) )
		{
			sBin_Output.Empty();		
			return false;
		}
		//�����һ���ַ��� ��-��������false
		if (sDec_Input.Mid(0,1) == "-" )
		{
			sBin_Output.Empty();		
			return false;
		}
	}

	if (!bSigned) // �Ƿ�����
	{
		unsigned int iNumerartor = (unsigned int)atof(sDec_Input); // �����ַ�������ֵת��Ϊ���Σ�ע��INT�͵����ֵ
		int iQuotient(0), iRemainder(0); //�̣�����
		bool bStop(TRUE);
		CString sTmp;
		sBin_Output.Empty();
		//��������2��ÿ�ε�������������
		while(bStop)
		{			
			iQuotient = iNumerartor/2;
			iRemainder = iNumerartor%2;
			sTmp.Format("%d",iRemainder); //����������
			sBin_Output += sTmp;
			iNumerartor = iQuotient; // ���̸���������
			if (iQuotient == 0)
			{
				bStop = FALSE;
			}
	 	}
	 	sBin_Output.MakeReverse(); //��ת�ַ���˳��
     	sBin_Output.TrimLeft("0");

	}else //������
	{
		//�з���λ ��-��
		if (sDec_Input.Mid(0,1) == "-" )
		{
			if (!(sDec_Input.GetLength() == 1)) // ����ֻ��һ�� ��-��ʱ����
			{
				sDec_Input.Delete(0,1); //����-���޳�
				unsigned int iNumerartor = (int) nMax - (unsigned int)atof(sDec_Input); // �����ַ�������ֵת��Ϊ���Σ�ע��INT�͵����ֵ
				int iQuotient(0), iRemainder(0); //�̣�����
				bool bStop(TRUE);
				CString sTmp;
				sBin_Output.Empty();
				//��������2��ÿ�ε�������������
				while(bStop)
				{			
					iQuotient = iNumerartor/2;
					iRemainder = iNumerartor%2;
					sTmp.Format("%d",iRemainder); //����������
					sBin_Output += sTmp;
					iNumerartor = iQuotient; // ���̸���������
					if (iQuotient == 0)
					{
						bStop = FALSE;
					}
				}
				int nZero = nBits - sBin_Output.GetLength() -1 ; //��Ҫ��0�ĸ���
				for (int i=0;i!=nZero;++i)
				{
					sBin_Output = sBin_Output + "0";
				}
				sBin_Output = sBin_Output + "1" ;
				sBin_Output.MakeReverse(); //��ת�ַ���˳��

			}
			else
			{
				sBin_Output.Empty();
			}			
			
		}
		else // �޷���λ ��-��
		{
			unsigned int iNumerartor = (unsigned int)atof(sDec_Input); // �����ַ�������ֵת��Ϊ���Σ�ע��INT�͵����ֵ
			int iQuotient(0), iRemainder(0); //�̣�����
			bool bStop(TRUE);
			CString sTmp;
			sBin_Output.Empty();
			//��������2��ÿ�ε�������������
			while(bStop)
			{			
				iQuotient = iNumerartor/2;
				iRemainder = iNumerartor%2;
				sTmp.Format("%d",iRemainder); //����������
				sBin_Output += sTmp;
				iNumerartor = iQuotient; // ���̸���������
				if (iQuotient == 0)
				{
					bStop = FALSE;
				}
			}
			sBin_Output.MakeReverse(); //��ת�ַ���˳��
			sBin_Output.TrimLeft("0");

		}		
	}

	return true;
}

bool CHBDconv::Bin2Dec(CString sBin_Input, CString &sDec_Output, bool bSigned)
{  
	//////////////////////////////////////////////////////////////////////////
	//
	// �� �����������ַ��� ת��Ϊ ʮ���������ַ��� 
	//
	// bSigned Ϊ true ʱ��Ϊ������ʮ���ƣ���Χ[-2147483648��2147483647]��Ĭ��
	// bSigned Ϊ false ʱ��Ϊ�޷���ʮ���ƣ���Χ[0,4294967295], ��ѡ
	//
	// ���� true ��ת���ɹ�
	// ���� false ��ת��ʧ��
	//
	//////////////////////////////////////////////////////////////////////////

	const int nBits = 32; // 32λ����Чλ��
	const double nMax = pow(2.0,nBits-1);   // 2147483648)
	double ResultSigned(0.0);
	double ResultUnsigned(0.0);

	//���λ�������� ���� false
	if (sBin_Input.GetLength() > nBits )  // nBits ��Ϊ32 λ
	{ 
		sDec_Output.Empty();
		return false;
	}

	//������� 0 ���� 1 ������ false
	for (int i=0;i!=sBin_Input.GetLength();++i) 
	{

		if (!(sBin_Input.Mid(i,1) == "0" || sBin_Input.Mid(i,1) =="1"))
		{
			sDec_Output.Empty();
			return false;
		}

	}

	if ( bSigned) //�з�����
	{		
		if (sBin_Input.GetLength()==nBits && sBin_Input.Mid(0,1) =="1" )  // �з���λ
		{ 			
			sBin_Input.Delete(0,1);  //������λ�޳�	
			sBin_Input.MakeReverse();			
			for(int i=0; i!=sBin_Input.GetLength();++i)
			{
				ResultSigned += atoi(sBin_Input.Mid(i,1))*pow(2.0,i);
			}
			ResultSigned = nMax - ResultSigned;
			sDec_Output.Format("%.0f",ResultSigned);
			sDec_Output = "-" + sDec_Output;
		}else //û�з���λ
		{
			sBin_Input.MakeReverse();
			for(int i=0; i!=sBin_Input.GetLength();++i)
			{
				ResultSigned += atoi(sBin_Input.Mid(i,1))*pow(2.0,i);
			}
			sDec_Output.Format("%.0f",ResultSigned);
		}

	}else       //�޷�����
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



