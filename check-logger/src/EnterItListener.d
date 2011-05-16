module EnterItListener;

import  dwt.DWT,
		dwt.widgets.Text,
		dwt.widgets.Event,
		dwt.widgets.Listener;

import  Integer=tango.text.convert.Integer,
		Float=tango.text.convert.Float;

import  AppWindow,
		CheckStore,
		Check;

class EnterItListener:Listener {
	
	AppWindow myWindow;
	
	this(AppWindow aw) {
		myWindow=aw;
	}
	
	void handleEvent(Event e) {
		
		Check.Check newcheck;

		newcheck.number=Integer.parse(myWindow.NumberField.getText());
		newcheck.date=myWindow.DateField.getText();
		newcheck.checkNo=Integer.parse(myWindow.CheckNoField.getText());
		newcheck.descr=myWindow.DescrField.getText();
		if(myWindow.DebitField.getText()=="") {
			newcheck.debit=0.00;
			newcheck.credit=Float.parse(myWindow.CreditField.getText());
		}
		else {
			newcheck.credit=0.00;
			newcheck.debit=Float.parse(myWindow.DebitField.getText());
		}
		newcheck.balance=Float.parse(myWindow.BalanceField.getText());
		
		CheckStore.CheckStore.getStore().allChecks~=newcheck;
		
		// write that check object to file
		CheckStore.CheckStore.getStore().writeToFile();
		
		// reset all fields
		myWindow.NumberVListener.NumberVerify=false;
		myWindow.DebitFieldVListener.process=false;
		myWindow.BalanceListener.process=false;
		
		myWindow.NumberField.setText(Integer.toString(newcheck.number+1));
		myWindow.CheckNoField.setText("");
		myWindow.DescrField.setText("");
		myWindow.DebitField.setText("0.00");
		myWindow.CreditField.setText("0.00");
		
		myWindow.BalanceField.setText(Float.toString(CheckStore.CheckStore.
			getStore().getRunningBalance()));
		myWindow.DebitFieldVListener.process=true;
		myWindow.BalanceListener.process=true;
		
	}
	
}