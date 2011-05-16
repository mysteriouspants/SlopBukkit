module DebitFieldListener;

import  dwt.widgets.Listener,
		dwt.widgets.Event,
		dwt.widgets.Text,
		dwt.DWT;

import tango.text.Util;

class DebitFieldListener:Listener {
	bool process=true;
	Text CreditField;
	Text DebitField;
	
	this(Text CField, Text DField) {
		CreditField=CField;
		DebitField=DField;
	}
	
	void handleEvent(Event e) {
		if(!process)
			return;
		if(CreditField.getText()!="") {
			process=false;
			CreditField.selectAll();
			CreditField.insert("");
			int tmp=DebitField.getCaretPosition();
			DebitField.selectAll();
			DebitField.insert("0.00");
			DebitField.setSelection(tmp);
			process=true;
		}
		switch(e.keyCode) {
		case DWT.BS:
			if(DebitField.getCaretPosition()<DebitField.getText().length) {
				if(DebitField.getText[DebitField.getCaretPosition-1]!='.') {
					e.doit=true;
					return;
				}
			}
			break;
		case DWT.DEL:
			if(DebitField.getCaretPosition()>0) {
				if(DebitField.getText()[DebitField.getCaretPosition()]!='.') {
					e.doit=true;
					return;
				}
			}
			break;
			default: // TODO: Add more stuff here to keep a maximum of two
				// digits after the decimal place
				if(e.character>='0'&&e.character<='9')
						e.doit=true;
				else
					e.doit=false;
				if(e.character=='.') { // in for trouble
					e.doit=false;
					char[] txt=DebitField.getText();
					int caret=DebitField.getCaretPosition();
					if(caret>=tango.text.Util.locate(txt, '.')||caret==0)
						return;
					process=false;
					DebitField.setText(txt[0..caret]~'.'~txt[
						tango.text.Util.locate(txt, '.')+1..$]);
					process=true;
				}
		}
	}
}