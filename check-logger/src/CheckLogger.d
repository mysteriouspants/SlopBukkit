/**
 * Check Logger.  A tool to help record personal checks written out to
 * restaraunts.  Built by FSDEV's Chris Miller in 2008.
 * Commissioned by Tyrone Towers.
 */
module CheckLogger;

import dwt.DWT,
	   dwt.widgets.Display,
	   dwt.widgets.FileDialog;

import Float = tango.text.convert.Float;

import AppWindow,
	   CheckStore;

void main ( char args[][] ) {
	
	Display d=new Display;
	
	AppWindow myWindow=new AppWindow(d);	
	
	FileDialog dialog=new FileDialog(myWindow, DWT.OPEN);
	
	auto blarg=dialog.open();
	
	CheckStore.CheckStore.initStore(blarg);
	
	myWindow.init();
	
	while (!myWindow.isDisposed ()) {
		if (!d.readAndDispatch())
			d.sleep ();
	}
	
	d.dispose();
	
}
