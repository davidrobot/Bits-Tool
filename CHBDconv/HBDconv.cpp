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
	// �� �����������ַ��� ת��Ϊ ʮ�����������ַ��� 
	//
	// ���ƶ���������Ϊ 32 λ
	//
	// ���� true ��ת���ɹ�
	// ���� false ��ת��ʧ��
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

	//���λ�������� ���� false
	if (sBin_Input.GetLength() > nBits )  // nBits ��Ϊ32 λ
	{ 
		sHex_Output.Empty();
		return false;
	}

	//������� 0 ���� 1 ������ false
	for (int i=0;i!=sBin_Input.GetLength();++i) 
	{
		
		if (!(sBin_Input.Mid(i,1) == "0" || sBin_Input.Mid(i,1) =="1"))
		{
			sHex_Output.Empty();
			return false;
		}
		
	}

	sHex_Output.Empty();
	intLen=sBin_Input.GetLength();  //��ȡ�ַ�������

	//�������С��4
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


	//������ȵ���4
	if (intLen==4)
	{	
		FullBin=sBin_Input;
		NumBlocks=1;
	}


	//������ȴ���4
	if (intLen>4 )
	{
		FullBin=sBin_Input;
		float TempDiv;
		float templen;
		CString stemp;

		templen = (float) sBin_Input.GetLength();
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
	// �� ʮ�����������ַ��� ת��Ϊ �����������ַ��� 
	//
	// ����ʮ����������Ϊ 8 λ
	//
	// ���� true ��ת���ɹ�
	// ���� false ��ת��ʧ��
	//
	//////////////////////////////////////////////////////////////////////////
	const int nBits = 32;
	
	sBin_Output.Empty();	
	sHex_Input.MakeUpper();  //������ת��Ϊ��д

	//���λ�������� ���� false
	if (sHex_Input.GetLength() > nBits/4 )  // nBits ��Ϊ32 λ
	{ 
		sBin_Output.Empty();
		return false;
	}	
		
	////�ж������Ƿ�Ϊʮ�����ƣ����Ƿ���false
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
	

	for ( i=0; i!=sHex_Input.GetLength(); ++i) //������Ϊ������
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
	sBin_Output.TrimLeft("0");     //��������ġ�0��
	if (sBin_Output.IsEmpty())
		sBin_Output ="0";

	return true;
}

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

	if (!bSigned) ///////////////////////////////////�Ƿ�����///////////////////////////////////////	 
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

	}else //////////////////////////////////  ������  ////////////////////////////////////////
	{
		//�и��� ��-��
		if (sDec_Input.Mid(0,1) == "-" )
		{
			sDec_Input.Delete(0,1); //����-���޳�
			sDec_Input.TrimLeft("0");

			if (!(sDec_Input.IsEmpty())) // �����Ϊ��
			{
				
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
				sBin_Output="0";
			}			
			
		}
		else // �޸��� ��-��
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
				iNumerartor = iQuotient;  // ���̸���������
				if (iQuotient == 0)
				{
					bStop = FALSE;
				}
			}
			sBin_Output.MakeReverse(); // ��ת�ַ���˳��
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


bool CHBDconv::Hex2Dec(CString sHex_Input, CString &sDec_Output, bool bSigned)
{

	//////////////////////////////////////////////////////////////////////////
	//
	// �� ʮ�����������ַ��� ת��Ϊ ʮ���������ַ���
	// 
	// ����ʮ����������Ϊ 8 λ
	//
	// ���� true ��ת���ɹ�
	// ���� false ��ת��ʧ��
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
	// �� ʮ���������ַ��� ת��Ϊ ʮ�����������ַ���
	// 
	// bSigned Ϊ true ʱ��Ϊ������ʮ���ƣ���Χ[-2147483648��2147483647]��Ĭ��
	// bSigned Ϊ false ʱ��Ϊ�޷���ʮ���ƣ���Χ[0,4294967295], ��ѡ
	//
	// ���� true ��ת���ɹ�
	// ���� false ��ת��ʧ��
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


