# Student-system

#include "stdafx.h"
#include "6_15.h"
#include "6_15Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CMy6_15App

BEGIN_MESSAGE_MAP(CMy6_15App, CWinApp)
	//{{AFX_MSG_MAP(CMy6_15App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy6_15App construction

CMy6_15App::CMy6_15App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMy6_15App object

CMy6_15App theApp;

/////////////////////////////////////////////////////////////////////////////
// CMy6_15App initialization

BOOL CMy6_15App::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CMy6_15Dlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}









//
#include "stdafx.h"
#include "6_15.h"
#include "6_15Dlg.h"
#include "xs_check.h"
#include "stu_check.h"
#include "js_check.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif	
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
struct student xs[400];
struct teacher js[200];
struct course kc[150];
int totalxs;
int totaljs;
int totalkc;
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy6_15Dlg dialog

CMy6_15Dlg::CMy6_15Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy6_15Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy6_15Dlg)
	m_M1 = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy6_15Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy6_15Dlg)
	DDX_Radio(pDX, IDC_M, m_M1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy6_15Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy6_15Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_IN, OnIn)
	ON_BN_CLICKED(IDC_M, OnM)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy6_15Dlg message handlers

BOOL CMy6_15Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy6_15Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy6_15Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy6_15Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy6_15Dlg::OnIn() 
{
	// TODO: Add your control notification handler code here
	int i,j,k;
	i=0;
	j=0;
	k=0;
	ifstream ins1,ins2,ins3,ins4,ins5;
    ins1.open("xs.dat",ios::in|ios::binary);
	ins2.open("js.dat",ios::in|ios::binary);
	ins3.open("kc.dat",ios::in|ios::binary);
	ins4.open("xschain.dat",ios::in|ios::binary);
	ins5.open("kcchain.dat",ios::in|ios::binary);
    if(!ins1){
		MessageBox("不能打开xs文件 !!!");
		exit(1);
	}
    ins1.seekg( 0, ios::end ) ;     //移动读指针到文件尾
    long posEnd1=ins1.tellg() ;		// 记录二进制文件末尾位置
    ins1.seekg( 0, ios::beg ) ;	    // 移动读指针到文件头
	if(!ins5){
		MessageBox("不能打开kcchain文件!!!");
		exit(1);
	}
	ins5.seekg( 0, ios::end ) ;     //移动读指针到文件尾
    long posEnd5=ins5.tellg() ;		// 记录二进制文件末尾位置
    ins5.seekg( 0, ios::beg ) ;		// 移动读指针到文件头
    while ( ins1.tellg() != posEnd1 ) {
		ins1.read((char*)&xs[i],sizeof(student));
		xs[i].root=NULL;
		while(ins5.tellg()!=posEnd5){
			studentname *p1,*p=new studentname;			
			ins5.read((char*)p,sizeof(studentname));
			p->next=NULL;
			//cout<<p->cnum<<"????"<<endl;
			//cout<<"ggggggggg"<<endl;			
			if(strcmp(xs[i].num,p->xh)==0){
			if(xs[i].root==NULL){
				xs[i].root=p;
			}
			else
			{p1=xs[i].root;
			while(p1->next){
				p1=p1->next;
			}
			p1->next=p;
			//cout<<p->xh<<endl;
			//cout<<"kkkk"<<endl;
			//getch();
			}
			}
			else
				{
					ins5.seekg(-sizeof(studentname),ios::cur);
					delete p;
					break;
				}
		}
		i++;
		totalxs=i;
	}
    ins1.close() ;
	ins5.close();
	if(!ins2){
		MessageBox("不能打开js文件!!!");
		exit(1);
	}
    ins2.seekg( 0, ios::end ) ;     //移动读指针到文件尾
    long posEnd2=ins2.tellg() ;		// 记录二进制文件末尾位置
    ins2.seekg( 0, ios::beg ) ;		// 移动读指针到文件头
    while ( ins2.tellg() != posEnd2 ){
		ins2.read((char*)&js[j],sizeof(teacher));
		j++;
		totaljs=j;
	}
    ins2.close() ;
	if(!ins3){
		MessageBox("不能打开kc文件!!!");
		exit(1);
	}
    ins3.seekg( 0, ios::end ) ;     //移动读指针到文件尾
    long posEnd3=ins3.tellg() ;		// 记录二进制文件末尾位置
    ins3.seekg( 0, ios::beg ) ;		// 移动读指针到文件头
	if(!ins4){
		MessageBox("不能打开xschain文件!!!");
		exit(1);
	}
	ins4.seekg( 0, ios::end ) ;     //移动读指针到文件尾
    long posEnd4=ins4.tellg() ;		// 记录二进制文件末尾位置
    ins4.seekg( 0, ios::beg ) ;		// 移动读指针到文件头
    while ( ins3.tellg() != posEnd3 ) {
		ins3.read((char*)&kc[k],sizeof(course));
		kc[k].root=NULL;
		//cout<<"kkkk"<<endl;
		while(ins4.tellg()!=posEnd4){
			coursename *p1,*p=new coursename;
			ins4.read((char*)p,sizeof(coursename));
			p->next=NULL;
			//cout<<p->snum<<"????"<<endl;
			//getch();
			if(strcmp(p->css,kc[k].cnum)==0){
			if(kc[k].root==NULL){
				kc[k].root=p;
				//cout<<p->css<<"lllll"<<endl;
			//getch();
			}
			else
			{p1=kc[k].root;
			while(p1->next){
				p1=p1->next;
			}
			p1->next=p;
			//cout<<p->css<<"oooooo"<<endl;
			//getch();
			}
			}
			else
				{
					ins4.seekg(-sizeof(coursename),ios::cur);
					delete p;
					break;
				}
		}
		k++;
		totalkc=k;
	}
    ins3.close() ;
	ins4.close();
	UpdateData(TRUE);
	xs_check ss;
	stu_check st;
	js_check tt;
	if(m_M1==0)
	{		
		if(ss.DoModal()==IDOK){};
	}
	if(m_M1==2)
	{		
		if(st.DoModal()==IDOK){};
	}		
    if(m_M1==1)
	{		
		if(tt.DoModal()==IDOK){};
	}		
	
}

void CMy6_15Dlg::OnM() 
{
	// TODO: Add your control notification handler code here

	
}










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
