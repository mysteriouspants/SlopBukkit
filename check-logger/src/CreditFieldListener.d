module CreditFieldListener;

import  dwt.widgets.Listener,
		dwt.widgets.Event,
		dwt.widgets.Text,
		dwt.DWT;

import DebitFieldListener;

class CreditFieldListener:Listener {
	
	Text CreditField;
	Text DebitField;
	DebitFieldListener other;
	
	this(Text CField, Text DField, DebitFieldListener o) {
		CreditField=CField;
		DebitField=DField;
		other=o;
	}
	
	void handleEvent(Event e) {
		if(!other.process)
			return;
		if(DebitField.getText()!="") {
			other.process=false;
			DebitField.selectAll();
			DebitField.insert("");
			int tmp=CreditField.getCaretPosition();
			CreditField.selectAll();
			CreditField.insert("0.00");
			CreditField.setSelection(tmp);
			other.process=true;
		}
		if(e.keyCode==DWT.BS&&CreditField.getCaretPosition()<CreditField.getText().length) {
			if(CreditField.getText[CreditField.getCaretPosition()-1]!='.') {
				e.doit=true;
				return;
			} else {
				e.doit=false;
				return;
			}
		}
		if(e.character>='0'&&e.character<='9')
			e.doit=true;
		else
			e.doit=false;
		if(e.character=='.') {
			e.doit=false;
			char[] txt=CreditField.getText();
			int caret=CreditField.getCaretPosition();
			if(caret>=tango.text.Util.locate(txt, '.')||caret==0)
				return;
			CreditField.setText(txt[0..caret]~'.'~txt[
				tango.text.Util.locate(txt, '.')+1..$]);
		}
	}
}