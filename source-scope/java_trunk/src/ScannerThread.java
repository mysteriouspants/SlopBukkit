/*
 *  ScannerThread.java - Source Scope Scanner Thread and GUI Modifier
 *  Copyright (C) 2007  FSDEV.NET
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, see http://www.gnu.org/licenses
 *  or write to the Free Software Foundation,Inc., 51 Franklin Street,
 *  Fifth Floor, Boston, MA 02110-1301  USA
 */

import java.util.Vector;

import javax.swing.JList;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableModel;

public class ScannerThread extends Thread {

	Directory dir;

	public ScannerThread(Directory dir) {

		this.dir = dir;
		if (colnames == null) {
			colnames = new Vector<Object>();
			colnames.add("");//"Directory");
			colnames.add("");//"Files");
			colnames.add("");//"Z-Order");
			colnames.add("");//"Lines");
		}

	}

	private static Vector<Object> colnames = null;

	private ScannerThread() {

	}

	SSWindow Window;

	@Override
	public void run() {

		dir.DeepScan();
		Window = Main.getWindow();

		// Number of Files and Directories

		long NumFiles = dir.getNumFiles();
		long NumDirectories = dir.getNumDirectories();
		Window.setTotalNumFiles(NumFiles);
		Window.setTotalNumDirectories(NumDirectories);

		// Mean, Max, and Min Files per Directory

		Window.setMeanFilesPerDirectory(dir.getMeanFilesDirectory());
		Window.setMaxFilesPerDirectory(dir.getMaxFilesDirectory());
		Window.setMinFilesPerDirectory(dir.getMinFilesDirectory());

		// Number of Lines (the last four rows)

		Window.setTotalJavadocCommentLines(dir.getNumJavadoc());
		Window.setTotalWhitespaceLines(dir.getNumWhitespace());
		Window.setTotalCodeLines(dir.getNumCodeLines());
		Window.setTotalLinesCode(dir.getNumLines());

		// find std. deviation of the # of files per directory

		/*
		 * std-dev= (sqrt(sum(pow(x-mean, 2)))/numitems
		 */

		float mean = dir.getMeanFilesDirectory();

		double sum = 0d;
		for (Directory d : dir.getDirectories())
			sum += Math.pow(d.getNumLocalFiles() - mean, 2);
		double stddev = Math.sqrt(sum / 2.0d);

		// Add Directories to the Table at the Bottom of Tab # 1

		JTable DetailTable = Window.getDetailTable();
		Directory[] dirs = new Directory[(int) dir.getNumDirectories()];
		dirs = dir.getDirectories().toArray(dirs);
		TableModel tm = new DefaultTableModel(dirs.length, 4);
		Vector<Vector<Object>> data = new Vector<Vector<Object>>();
		Vector<Object> temp;
		double zscore;
		for (int i = 0; i != dirs.length; i++) {
			// Directories Files Z-Order Lines
			//       0       1      2      3
			temp = new Vector<Object>();
			if (dirs[i] == null) {
				continue;
			}
			temp.add(dirs[i].getFile().getName());
			temp.add(dirs[i].getNumLocalFiles());
			zscore = zscore(stddev, mean, dirs[i].getNumLocalFiles());
			//if(dirs[i].getNumLocalFiles()>mean)
			//	zscore*=-1.0d;
			temp.add(((Double) (zscore)).toString());
			temp.add(dirs[i].getNumLocalLines());
			data.add(temp);
		}
		tm = new DefaultTableModel(data, colnames);
		DetailTable.setModel(tm);

		// Add all files to the file list on the detail tab

		JList FileList = Window.getFileList();
		SourceFile[] unconverted_files = new SourceFile[dir.getFiles().size()];
		unconverted_files = dir.getFiles().toArray(unconverted_files);
		ListFile[] converted_files = new ListFile[unconverted_files.length];
		for (int i = 0; i != converted_files.length
				&& i != unconverted_files.length; i++) {
			converted_files[i] = new ListFile(unconverted_files[i].getFile());
		}
		FileList.setListData(converted_files);

	}

	private static synchronized double zscore(double x, double y, double z) {

		return (z - y) / x;

	}

}
