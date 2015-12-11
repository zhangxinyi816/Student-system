// JS_ADDMARK.cpp : implementation file
//

#include "stdafx.h"
#include "6_15.h"
#include "JS_ADDMARK.h"
#include "save.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// JS_ADDMARK dialog


JS_ADDMARK::JS_ADDMARK(CWnd* pParent /*=NULL*/)
	: CDialog(JS_ADDMARK::IDD, pParent)
{
	//{{AFX_DATA_INIT(JS_ADDMARK)
	m_NUM = _T("");
	m_PSCJ = 0.0;
	m_SNUM = _T("");
	m_QMCJ = 0.0;
	m_CNUM = _T("");
	//}}AFX_DATA_INIT
}


void JS_ADDMARK::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(JS_ADDMARK)
	DDX_Control(pDX, IDC_XS_LIST, m_XS_LIST);
	DDX_Text(pDX, IDC_NUM, m_NUM);
	DDX_Text(pDX, IDC_PSCJ, m_PSCJ);
	DDX_Text(pDX, IDC_SNUM, m_SNUM);
	DDX_Text(pDX, IDC_QMCJ, m_QMCJ);
	DDX_Text(pDX, IDC_CNUM, m_CNUM);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(JS_ADDMARK, CDialog)
	//{{AFX_MSG_MAP(JS_ADDMARK)
	ON_BN_CLICKED(IDC_OKSHOW, OnOkshow)
	ON_BN_CLICKED(IDC_OKADD, OnOkadd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// JS_ADDMARK message handlers

BOOL JS_ADDMARK::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_XS_LIST.InsertColumn(0,"姓名",LVCFMT_CENTER,80);
	m_XS_LIST.InsertColumn(1,"学号",LVCFMT_CENTER,80);
	m_XS_LIST.InsertColumn(2,"班级",LVCFMT_CENTER,80);
	m_XS_LIST.InsertColumn(3,"专业",LVCFMT_CENTER,80);
	m_XS_LIST.InsertColumn(4,"该课序号",LVCFMT_CENTER,80);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void JS_ADDMARK::OnOkshow() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int i,j,k,a;
	a=0;
	for(j=0;j<totaljs;j++){
		if(strcmp(js[j].num,m_NUM)==0)
			break;
	}
	m_XS_LIST.DeleteAllItems();
	for(k=0;k<totalkc;k++){
		if(strcmp(kc[k].cnum,js[j].course)==0){
			coursename *p;
			p=kc[k].root;
			while(p){
				for(i=0;i<totalxs;i++){
					if(strcmp(p->snum,xs[i].num)==0){
						break;
					}
				}
				m_XS_LIST.InsertItem(a,xs[i].name);
	            m_XS_LIST.SetItemText(a,1,xs[i].num);
	            m_XS_LIST.SetItemText(a,2,xs[i].bj);
	            m_XS_LIST.SetItemText(a,3,xs[i].zy);
				m_XS_LIST.SetItemText(a,4,p->css);
				p=p->next;
			}			
		}
	}
}

void JS_ADDMARK::OnOkadd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int i;
	studentname *st,*p1=new studentname;
	for(i=0;i<totalxs;i++){
		if(strcmp(xs[i].num,m_SNUM)==0){
			st=xs[i].root;
			while(!st==NULL){
				if(strcmp(st->cnum,m_CNUM)==0){
					st->pscj=m_PSCJ;
					st->qmcj=m_QMCJ;
					st->issubmit=true;
					st->cj=st->pscj*0.3+st->qmcj*0.7;
					if(st->cj>100)
					{
		            MessageBox("你输入的成绩有误！！！请重新输入！！！");	 
					}
	                else if(st->cj>=90&&st->cj<=100)  st->jd=4.0;
	                else if(st->cj>=85)  st->jd=3.7;
	                else if(st->cj>=82)  st->jd=3.3;
	                else if(st->cj>=78)  st->jd=3.0;
	                else if(st->cj>=75)  st->jd=2.7;
	                else if(st->cj>=72)  st->jd=2.3;
	                else if(st->cj>=68)  st->jd=2.0;
	                else if(st->cj>=66)  st->jd=1.7;
	                else if(st->cj>=64)  st->jd=1.3;
	                else if(st->cj>=60)  st->jd=1.0;
	                else  st->jd=0;
					MessageBox("添加成功！！！");
					//cout<<"成绩"<<st->jd<<endl;
					//getch();
					break;
				}				
				st=st->next;
			}
			if(st==NULL){
				MessageBox("该同学未选该课程！！！");
			}
			break;
		}
	}
	if(i==totalxs){
			MessageBox("该同学不存在！！！");
			}
}

void JS_ADDMARK::OnCancel() 
{
	// TODO: Add extra cleanup here
	save s;
	s.savecourse();
	s.savestudent();
	s.saveteacher();	
	CDialog::OnCancel();
}

void JS_ADDMARK::OnOK() 
{
	// TODO: Add extra validation here
	save s;
	s.savecourse();
	s.savestudent();
	s.saveteacher();
	CDialog::OnOK();
}






// js_op.cpp : implementation file
//

#include "stdafx.h"
#include "6_15.h"
#include "js_op.h"
#include "js_xgcode.h"
#include "JS_ADDMARK.h"
#include "JS_SELECTMARK.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// js_op dialog


js_op::js_op(CWnd* pParent /*=NULL*/)
	: CDialog(js_op::IDD, pParent)
{
	//{{AFX_DATA_INIT(js_op)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void js_op::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(js_op)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(js_op, CDialog)
	//{{AFX_MSG_MAP(js_op)
	ON_BN_CLICKED(IDC_XGCODE, OnXgcode)
	ON_BN_CLICKED(IDC_ADDMARK, OnAddmark)
	ON_BN_CLICKED(IDC_CXCJ, OnCxcj)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// js_op message handlers

void js_op::OnXgcode() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	js_xgcode jx;
	jx.DoModal();
	
}

void js_op::OnAddmark() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	JS_ADDMARK JA;
	JA.DoModal();

	
}

void js_op::OnCxcj() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	JS_SELECTMARK JS;
	JS.DoModal();
	
}






// js_check.cpp : implementation file
//

#include "stdafx.h"
#include "6_15.h"
#include "js_check.h"
#include "js_op.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// js_check dialog


js_check::js_check(CWnd* pParent /*=NULL*/)
	: CDialog(js_check::IDD, pParent)
{
	//{{AFX_DATA_INIT(js_check)
	m_CODE = _T("");
	m_NUM = _T("");
	//}}AFX_DATA_INIT
}


void js_check::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(js_check)
	DDX_Text(pDX, IDC_CODE, m_CODE);
	DDX_Text(pDX, IDC_NUM, m_NUM);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(js_check, CDialog)
	//{{AFX_MSG_MAP(js_check)
	ON_BN_CLICKED(IDC_IN, OnIn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// js_check message handlers

void js_check::OnIn() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	js_op jo;
	int i;
	if(m_NUM==""){
		MessageBox("请输入工号！！！");
	}
	else{
	for(i=0;i<totaljs;i++){
	if(strcmp(js[i].num,m_NUM)==0){
		if(strcmp(js[i].code,m_CODE)==0){
			jo.DoModal();
			break;
		}
		else
		{MessageBox("你的密码输入有误，请重新输入!!!");
		break;
		}
	}
	}
	if(i==totaljs){
		MessageBox("该教师不存在!!!");
	}
	}	
}





// JS_SELECTMARK.cpp : implementation file
//

#include "stdafx.h"
#include "6_15.h"
#include "JS_SELECTMARK.h"
#include "sjcl.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// JS_SELECTMARK dialog


JS_SELECTMARK::JS_SELECTMARK(CWnd* pParent /*=NULL*/)
	: CDialog(JS_SELECTMARK::IDD, pParent)
{
	//{{AFX_DATA_INIT(JS_SELECTMARK)
	m_NUM = _T("");
	m_NUM1 = _T("");
	m_ZY = _T("");
	m_ZY1 = _T("");
	m_BJ = _T("");
	//}}AFX_DATA_INIT
}


void JS_SELECTMARK::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(JS_SELECTMARK)
	DDX_Control(pDX, IDC_ZY_LIST, m_ZY_LIST);
	DDX_Control(pDX, IDC_GR_LIST, m_GR_LIST);
	DDX_Control(pDX, IDC_BJ_LIST, m_BJ_LIST);
	DDX_Text(pDX, IDC_NUM, m_NUM);
	DDX_Text(pDX, IDC_NUM1, m_NUM1);
	DDX_CBString(pDX, IDC_ZY, m_ZY);
	DDX_CBString(pDX, IDC_ZY1, m_ZY1);
	DDX_CBString(pDX, IDC_BJ, m_BJ);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(JS_SELECTMARK, CDialog)
	//{{AFX_MSG_MAP(JS_SELECTMARK)
	ON_BN_CLICKED(IDC_ZYCX, OnZycx)
	ON_BN_CLICKED(IDC_BJCX, OnBjcx)
	ON_BN_CLICKED(IDC_GRCX, OnGrcx)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// JS_SELECTMARK message handlers

BOOL JS_SELECTMARK::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ZY_LIST.InsertColumn(0,"学号",LVCFMT_CENTER,80);
	m_ZY_LIST.InsertColumn(1,"姓名",LVCFMT_CENTER,80);
	m_ZY_LIST.InsertColumn(2,"班级",LVCFMT_CENTER,80);
	m_ZY_LIST.InsertColumn(3,"专业",LVCFMT_CENTER,80);
	m_ZY_LIST.InsertColumn(4,"平均学分绩点",LVCFMT_CENTER,120);
	m_ZY_LIST.InsertColumn(5,"专业排名",LVCFMT_CENTER,80);
	m_BJ_LIST.InsertColumn(0,"学号",LVCFMT_CENTER,80);
	m_BJ_LIST.InsertColumn(1,"姓名",LVCFMT_CENTER,80);
	m_BJ_LIST.InsertColumn(2,"班级",LVCFMT_CENTER,80);
	m_BJ_LIST.InsertColumn(3,"专业",LVCFMT_CENTER,80);
	m_BJ_LIST.InsertColumn(4,"平均学分绩点",LVCFMT_CENTER,120);
	m_BJ_LIST.InsertColumn(5,"班级排名",LVCFMT_CENTER,80);
	m_GR_LIST.InsertColumn(0,"学号",LVCFMT_CENTER,80);
	m_GR_LIST.InsertColumn(1,"姓名",LVCFMT_CENTER,80);
	m_GR_LIST.InsertColumn(2,"班级",LVCFMT_CENTER,60);
	m_GR_LIST.InsertColumn(3,"专业",LVCFMT_CENTER,80);
	m_GR_LIST.InsertColumn(4,"平均学分绩点",LVCFMT_CENTER,120);
	m_GR_LIST.InsertColumn(5,"班级排名",LVCFMT_CENTER,80);
	m_GR_LIST.InsertColumn(6,"专业排名",LVCFMT_CENTER,80);	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void JS_SELECTMARK::OnZycx() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	sjcl sj;
	int i,m,j,a;
	m=0;
	a=0;
	char zy[10];
	strcpy(zy,m_ZY);
	sj.cal();
	sj.zypm(zy);
	struct student s[200];
	for(i=0;i<totalxs;i++){
		if(strcmp(xs[i].zy,m_ZY)==0){
		s[m]=xs[i];
		m++;
		}
	}
	m_ZY_LIST.DeleteAllItems();
	for(j=0;j<m;j++){
	CString temp;
	//MessageBox("这是什么？");
	/*m_ZY_LIST.InsertColumn(0,"学号",LVCFMT_CENTER,50);
	m_ZY_LIST.InsertColumn(1,"姓名",LVCFMT_CENTER,50);
	m_ZY_LIST.InsertColumn(2,"班级",LVCFMT_CENTER,80);
	m_ZY_LIST.InsertColumn(3,"专业",LVCFMT_CENTER,80);
	m_ZY_LIST.InsertColumn(4,"平均学分绩点",LVCFMT_CENTER,60);
	m_ZY_LIST.InsertColumn(5,"专业排名",LVCFMT_CENTER,60);*/
	m_ZY_LIST.InsertItem(a,s[j].num);
	m_ZY_LIST.SetItemText(a,1,s[j].name);
	m_ZY_LIST.SetItemText(a,2,s[j].bj);
	m_ZY_LIST.SetItemText(a,3,s[j].zy);
	temp.Format("%f",s[j].jd);
	m_ZY_LIST.SetItemText(a,4,temp);
	temp.Format("%d",s[j].zymc);
	m_ZY_LIST.SetItemText(a,5,temp);
	a++;
	}

	
}

void JS_SELECTMARK::OnBjcx() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	sjcl sj;
	int i,m,j,a;
	m=0;
	a=0;
	char zy[10];
	char bj[10];
	strcpy(bj,m_BJ);
	strcpy(zy,m_ZY1);
	sj.cal();
	sj.bjpm(zy,bj);
	struct student s[40];
	for(i=0;i<totalxs;i++){
		if(strcmp(xs[i].bj,m_BJ)==0&&strcmp(xs[i].zy,m_ZY1)==0){
		s[m]=xs[i];
		m++;
		}
	}
	m_BJ_LIST.DeleteAllItems();
	for(j=0;j<m;j++){
	CString temp;
	//MessageBox("这是什么？");
	/*m_ZY_LIST.InsertColumn(0,"学号",LVCFMT_CENTER,50);
	m_ZY_LIST.InsertColumn(1,"姓名",LVCFMT_CENTER,50);
	m_ZY_LIST.InsertColumn(2,"班级",LVCFMT_CENTER,80);
	m_ZY_LIST.InsertColumn(3,"专业",LVCFMT_CENTER,80);
	m_ZY_LIST.InsertColumn(4,"平均学分绩点",LVCFMT_CENTER,60);
	m_ZY_LIST.InsertColumn(5,"专业排名",LVCFMT_CENTER,60);*/
	m_BJ_LIST.InsertItem(a,s[j].num);
	m_BJ_LIST.SetItemText(a,1,s[j].name);
	m_BJ_LIST.SetItemText(a,2,s[j].bj);
	m_BJ_LIST.SetItemText(a,3,s[j].zy);
	temp.Format("%f",s[j].jd);
	m_BJ_LIST.SetItemText(a,4,temp);
	temp.Format("%d",s[j].bjmc);
	m_BJ_LIST.SetItemText(a,5,temp);
	a++;
	}
	
}

void JS_SELECTMARK::OnGrcx() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int i;
	if(m_NUM1==""){
		MessageBox("请输入学号！！！");
	}
	else{
	for(i=0;i<totalxs;i++){
		if(strcmp(xs[i].num,m_NUM1)==0){
			    CString temp;
				m_GR_LIST.DeleteAllItems();
				m_GR_LIST.InsertItem(0,xs[i].num);
	            m_GR_LIST.SetItemText(0,1,xs[i].name);
	            m_GR_LIST.SetItemText(0,2,xs[i].bj);
	            m_GR_LIST.SetItemText(0,3,xs[i].zy);
	            temp.Format("%f",xs[i].jd);
	            m_GR_LIST.SetItemText(0,4,temp);
	            temp.Format("%d",xs[i].bjmc);
	            m_GR_LIST.SetItemText(0,5,temp);
				temp.Format("%d",xs[i].zymc);
	            m_GR_LIST.SetItemText(0,6,temp);
				break;
		}
	}
	if(i==totalxs){
		MessageBox("你查找的同学不存在！！！");
	}
	}
	
	
}







// js_xgcode.cpp : implementation file
//

#include "stdafx.h"
#include "6_15.h"
#include "js_xgcode.h"
#include "save.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// js_xgcode dialog


js_xgcode::js_xgcode(CWnd* pParent /*=NULL*/)
	: CDialog(js_xgcode::IDD, pParent)
{
	//{{AFX_DATA_INIT(js_xgcode)
	m_N1 = _T("");
	m_N2 = _T("");
	m_O = _T("");
	//}}AFX_DATA_INIT
}


void js_xgcode::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(js_xgcode)
	DDX_Text(pDX, IDC_NCODE1, m_N1);
	DDX_Text(pDX, IDC_NCODE2, m_N2);
	DDX_Text(pDX, IDC_OCODE, m_O);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(js_xgcode, CDialog)
	//{{AFX_MSG_MAP(js_xgcode)
	ON_BN_CLICKED(IDC_OK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// js_xgcode message handlers

void js_xgcode::OnOk() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int i;
	i=0;
	if(strcmp(js[i].code,m_O)==0){
		if(strcmp(m_N1,m_N2)==0){
		strcpy(js[i].code,m_N1);
		MessageBox("密码修改成功！！！");
		}
		else
			MessageBox("前后两次输入的密码不一致，请重新输入！！！");
	}
	else
		MessageBox("旧密码输入有误，请重新输入！！！");
	
}

void js_xgcode::OnCancel() 
{
	// TODO: Add extra cleanup here
	save s;
	s.saveteacher();
	CDialog::OnCancel();
}

void js_xgcode::OnOK() 
{
	// TODO: Add extra validation here
	save s;
	s.saveteacher();
	CDialog::OnOK();
}





