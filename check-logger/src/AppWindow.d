module AppWindow;

import tango.io.Stdout;
import Integer=tango.text.convert.Integer;
import Float=tango.text.convert.Float;
import tango.text.Util;

import  dwt.DWT,
		dwt.widgets.Shell,
		dwt.layout.GridLayout,
		dwt.layout.GridData,
		dwt.widgets.Display,
		dwt.widgets.Listener,
		dwt.widgets.Event,
		dwt.widgets.Text,
		dwt.widgets.Button,
		dwt.widgets.Label;

import CheckStore,
	   Check,
	   NumberFieldVListener,
	   NumberFieldEscListener,
	   DateFieldListener,
	   DebitFieldListener,
	   CreditFieldListener,
	   BalanceVListener,
	   EnterItListener;

class AppWindow : Shell {
	
	Label NumberLabel;		Text  NumberField;		GridData NumberData;
	Label DateLabel;		Text  DateField;		GridData DateData;
	Label CheckNoLabel;		Text  CheckNoField;		GridData CheckNoData;
	Label DescrLabel;		Text  DescrField;		GridData DescrData;
	Label CodeLabel;		Text  CodeField;		GridData CodeData;
	Label DebitLabel;		Text  DebitField;		GridData DebitData;
	Label CreditLabel;		Text  CreditField;		GridData CreditData;
	Label BalanceLabel;		Text  BalanceField;		GridData BalanceData;
	
	Button EnterIt;									GridData EnterItData;
	
	int Number=0;
	
	NumberFieldVListener		NumberVListener;
	NumberFieldEscListener		NumberEscListener;
	DateFieldListener			DateFieldKListener;
	DebitFieldListener			DebitFieldVListener;
	CreditFieldListener			CreditFieldVListener;
	BalanceVListener			BalanceListener;
	EnterItListener				EnterListener;
	
	this(Display d) {
		super(d);
		
		this.setText("Cheque Logger");
	}
	
	int getNumber() {
		return Number;
	}
	
	void init() {
		
		GridLayout gl=new GridLayout();
		gl.numColumns=4;
		this.setLayout(gl);
		
		NumberLabel=new Label(this, DWT.NULL);
		NumberLabel.setText("Number");
		NumberField=new Text(this, DWT.SINGLE);
		NumberData=new GridData();
		NumberData.grabExcessHorizontalSpace=true;
		NumberData.horizontalAlignment=GridData.FILL;
		NumberField.setLayoutData(NumberData);
		NumberVListener=new NumberFieldVListener();
		NumberField.addListener(DWT.Verify, NumberVListener);
		NumberEscListener=new NumberFieldEscListener(NumberField, NumberVListener, this);
		NumberField.addListener(DWT.KeyUp, NumberEscListener);
		
		DateLabel=new Label(this, DWT.NULL);
		DateLabel.setText("Date");
		DateField=new Text(this, DWT.SINGLE);
		DateField.setText("MM/DD/YYYY");
		DateData=new GridData();
		DateData.grabExcessHorizontalSpace=true;
		DateData.horizontalAlignment=GridData.FILL;
		DateField.setLayoutData(DateData);
		DateFieldKListener=new DateFieldListener(DateField);
		DateField.addListener(DWT.Verify, DateFieldKListener);
		
		CheckNoLabel=new Label(this, DWT.NULL);
		CheckNoLabel.setText("Check Number");
		CheckNoField=new Text(this, DWT.SINGLE);
		CheckNoData=new GridData();
		CheckNoData.grabExcessHorizontalSpace=true;
		CheckNoData.horizontalAlignment=GridData.FILL;
		CheckNoField.setLayoutData(CheckNoData);
		Listener CheckNoVListener=new class() Listener {
			void handleEvent(Event e) {
				if(e.character<'0'||e.character>'9')
					e.doit=false;
			}
		};
		CheckNoField.addListener(DWT.Verify, CheckNoVListener);
		
		CodeLabel=new Label(this, DWT.NULL);
		CodeLabel.setText("Code");
		CodeField=new Text(this, DWT.SINGLE);
		CodeData=new GridData();
		CodeData.grabExcessHorizontalSpace=true;
		CodeData.horizontalAlignment=GridData.FILL;
		CodeField.setLayoutData(CheckNoData);
		Listener CodeFieldVListener=new class() Listener {
			void handleEvent(Event e) {
				if((e.character<'0'||e.character>'9')
						&&(e.character<'a'||e.character>'z')
						&&(e.character<'A'||e.character>'Z'))
					e.doit=false;
			}
		};
		CodeField.addListener(DWT.Verify, CodeFieldVListener);
		
		DescrLabel=new Label(this, DWT.NULL);
		DescrLabel.setText("Description");
		DescrField=new Text(this, DWT.SINGLE);
		DescrData=new GridData();
		DescrData.grabExcessHorizontalSpace=true;
		DescrData.grabExcessVerticalSpace=true;
		DescrData.horizontalAlignment=GridData.FILL;
		DescrData.verticalAlignment=GridData.FILL;
		DescrData.horizontalSpan=3;
		DescrField.setLayoutData(DescrData);
		Listener DescrFieldVListener=new class() Listener {
			void handleEvent(Event e) {
				if(e.character==',')
					e.doit=false;
			}
		};
		DescrField.addListener(DWT.Verify, DescrFieldVListener);
		
		DebitLabel=new Label(this, DWT.NULL);
		DebitLabel.setText("Debit");
		DebitField=new Text(this, DWT.SINGLE);
		DebitData=new GridData();
		DebitData.grabExcessHorizontalSpace=true;
		DebitData.horizontalAlignment=GridData.FILL;
		DebitField.setLayoutData(DebitData);
		DebitField.setText = "0.00";
		
		CreditLabel=new Label(this, DWT.NULL);
		CreditLabel.setText("Credit");
		CreditField=new Text(this, DWT.SINGLE);
		CreditData=new GridData();
		CreditData.grabExcessHorizontalSpace=true;
		CreditData.horizontalAlignment=GridData.FILL;
		CreditField.setLayoutData(CreditData);
		CreditField.setText = "0.00";
		DebitFieldVListener=new DebitFieldListener(CreditField, DebitField);
		DebitField.addListener(DWT.Verify, DebitFieldVListener);
		CreditFieldVListener=new CreditFieldListener(CreditField, DebitField, DebitFieldVListener);
		CreditField.addListener(DWT.Verify, CreditFieldVListener);
		
		BalanceLabel=new Label(this, DWT.NULL);
		BalanceLabel.setText("Balance");
		BalanceField=new Text(this, DWT.SINGLE);
		BalanceData=new GridData();
		BalanceData.grabExcessHorizontalSpace=true;
		BalanceData.horizontalAlignment=GridData.FILL;
		BalanceField.setLayoutData(BalanceData);
		BalanceField.setText(Float.toString(CheckStore.CheckStore.getStore().getRunningBalance()));
		BalanceListener=new BalanceVListener(BalanceField);
		BalanceField.addListener(DWT.Verify, BalanceListener);
		
		
		EnterIt=new Button(this, DWT.PUSH);
		EnterIt.setText("Record Check");
		EnterItData=new GridData();
		EnterItData.horizontalSpan=2;
		EnterItData.grabExcessHorizontalSpace=true;
		EnterItData.horizontalAlignment=GridData.CENTER;
		EnterItData.verticalAlignment=GridData.CENTER;
		EnterIt.setLayoutData(EnterItData);
		EnterListener=new EnterItListener(this);
		EnterIt.addListener(DWT.Selection, EnterListener);
		
		this.pack();
		this.open();
		
		this.setMinimumSize = this.getSize();
	}
	
	void updateBalance(float f) {
		float cumulative=CheckStore.CheckStore.getStore().getRunningBalance();
		BalanceListener.process=false;
		BalanceField.setText(Float.toString(f+cumulative));
		BalanceListener.process=true;
	}
	
}
