module DateFieldListener;

import  dwt.widgets.Listener,
		dwt.widgets.Event,
		dwt.widgets.Text;

class DateFieldListener:Listener {
	
	Text DateField;
	
	this(Text field) {
		DateField=field;
	}
	
	bool ignore=false;
	void handleEvent(Event e) {
		if(ignore)
			return;
		e.doit=false; // handle input manually
		ignore=true;
		if(e.character>='0'&&e.character<='9') {
			if(DateField.getCaretPosition()>=DateField.getText().length) {
				ignore=false;
				return;
			} if(DateField.getText()[DateField.getCaretPosition()]=='/')
				DateField.setSelection(DateField.getCaretPosition()+1);
			char[] tmp=DateField.getText();
			tmp[DateField.getCaretPosition()]=e.character;
			int itmp=DateField.getCaretPosition()+1;
			DateField.setSelection(DateField.getCaretPosition()+1);
			if(DateField.getCaretPosition()>=DateField.getText().length) {
				DateField.selectAll();
				DateField.insert(tmp);
				DateField.setSelection(itmp);
				ignore=false;
				return;
			}
			else if(DateField.getText()[DateField.getCaretPosition()]=='/')
				DateField.setSelection(DateField.getCaretPosition()+1);
			DateField.selectAll();
			DateField.insert(tmp);
			DateField.setSelection(itmp);
			if(DateField.getText()[DateField.getCaretPosition()]=='/')
				DateField.setSelection(DateField.getCaretPosition()+1);
			ignore=false;
			return;
		}
		ignore=false;
	}
}