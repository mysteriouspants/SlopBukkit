/*
 *  SSWindow.java - Source Scope Main Window and Interface
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

import java.awt.Dimension;
import java.awt.Rectangle;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JEditorPane;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.border.TitledBorder;
import javax.swing.table.TableColumn;

public class SSWindow extends JFrame {
	
	private Directory ProjectDirectory;

	private static final long serialVersionUID = 1L;
	private JPanel jPanel = null;
	private JTextField ProjectLocation = null;
	private JButton BrowseButton = null;
	private JButton ScanButton = null;
	private JLabel jLabel = null;
	private JProgressBar ProgressBar = null;
	private JPanel jPanel1 = null;
	private JPanel jPanel2 = null;
	private JLabel jLabel1 = null;
	private JLabel jLabel2 = null;
	private JLabel jLabel3 = null;
	private JLabel jLabel4 = null;
	private JLabel jLabel5 = null;
	private JLabel FileName = null;
	private JLabel FileSize = null;
	private JLabel NumCharacters = null;
	private JLabel NumImports = null;
	private JLabel FileLines = null;
	private JLabel jLabel8 = null;
	private JScrollPane jScrollPane = null;
	private JList FileList = null;
	private JScrollPane jScrollPane1 = null;
	private JEditorPane FilePreview = null;
	private JLabel FilesLinesCode = null;
	private JLabel jLabel10 = null;
	private JLabel FileLinesComment = null;
	/**
	 * This is the default constructor
	 */
	public SSWindow() {
		super();
		initialize();
	}

	/**
	 * This method initializes this
	 * 
	 * @return void
	 */
	private void initialize() {
		this.setSize(44, 72);
		this.setPreferredSize(new Dimension(469, 535));
		this.setMaximumSize(new Dimension(479, 531));
		this.setMinimumSize(new Dimension(477, 529));
		this.setResizable(false);
		this.setContentPane(getJPanel());
		this.setTitle("Inspector Java");
		this.addWindowListener(new java.awt.event.WindowAdapter() {
			public void windowClosing(java.awt.event.WindowEvent e) {
				System.exit(0);
			}
		});
	}

	/**
	 * This method initializes jPanel	
	 * 	
	 * @return javax.swing.JPanel	
	 */
	private JPanel getJPanel() {
		if (jPanel == null) {
			jLabel = new JLabel();
			jLabel.setBounds(new Rectangle(15, 45, 76, 16));
			jLabel.setText("Progress:");
			jPanel = new JPanel();
			jPanel.setLayout(null);
			jPanel.add(getProjectLocation(), null);
			jPanel.add(getBrowseButton(), null);
			jPanel.add(getScanButton(), null);
			jPanel.add(jLabel, null);
			jPanel.add(getProgressBar(), null);
			jPanel.add(getJTabbedPane(), null);
		}
		return jPanel;
	}

	/**
	 * This method initializes ProjectLocation	
	 * 	
	 * @return javax.swing.JTextField	
	 */
	private JTextField getProjectLocation() {
		if (ProjectLocation == null) {
			ProjectLocation = new JTextField();
			ProjectLocation.setBounds(new Rectangle(15, 15, 241, 19));
			ProjectLocation.setEnabled(true);
			ProjectLocation.setEditable(false);
		}
		return ProjectLocation;
	}

	/**
	 * This method initializes BrowseButton	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getBrowseButton() {
		if (BrowseButton == null) {
			BrowseButton = new JButton();
			BrowseButton.setBounds(new Rectangle(270, 15, 91, 19));
			BrowseButton.setText("Browse");
			BrowseButton.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					if(st!=null)
						st.interrupt();
					JFileChooser DirectoryChooser=new JFileChooser();
					DirectoryChooser.setFileSelectionMode(
							JFileChooser.DIRECTORIES_ONLY
						);
					File DirectoryFolder;
					DirectoryChooser.showOpenDialog(Main.getWindow());
					DirectoryFolder=DirectoryChooser.getSelectedFile();
					for(File f:DirectoryFolder.listFiles()) {
						if(f.isDirectory() &&
								"src".equalsIgnoreCase(f.getName())) {
							DirectoryFolder=f;
							break;
						}
					}
					ProjectLocation.setText(DirectoryFolder.getAbsolutePath());
					ProjectDirectory=new Directory(DirectoryFolder);
					ScanButton.setEnabled(true);
				}
			});
		}
		return BrowseButton;
	}
	
	public Directory getProjectDirectory() { return ProjectDirectory; }

	private ScannerThread st;
	
	/**
	 * This method initializes ScanButton	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getScanButton() {
		if (ScanButton == null) {
			ScanButton = new JButton();
			ScanButton.setBounds(new Rectangle(375, 15, 76, 19));
			ScanButton.setEnabled(false);
			ScanButton.setText("Scan");
			ScanButton.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					if(st!=null)
						st.interrupt();
					ProjectDirectory=new Directory(ProjectDirectory.getFile());
					st=new ScannerThread(ProjectDirectory);
					st.start();
				}
			});
		}
		return ScanButton;
	}
	
	private JTabbedPane jTabbedPane = null;
	private JPanel jPanel3 = null;
	private JLabel jLabel6 = null;
	private JLabel NumFiles = null;
	private JLabel jLabel9 = null;
	private JLabel NumDirectories = null;
	private JLabel jLabel12 = null;
	private JLabel MeanFilesDir = null;
	private JLabel jLabel14 = null;
	private JLabel jLabel15 = null;
	private JLabel jLabel16 = null;
	private JLabel jLabel17 = null;
	private JLabel jLabel18 = null;
	private JLabel jLabel19 = null;
	private JLabel MaxFilesDir = null;
	private JLabel MinFilesDir = null;
	private JLabel TotalLinesCode = null;
	private JLabel JavadocLines = null;
	private JLabel CodeLines = null;
	private JLabel WhitespaceLines = null;
	private JScrollPane jScrollPane2 = null;
	private JTable DetailTable = null;
	/**
	 * This method initializes ProgressBar	
	 * 	
	 * @return javax.swing.JProgressBar	
	 */
	private JProgressBar getProgressBar() {
		if (ProgressBar == null) {
			ProgressBar = new JProgressBar();
			ProgressBar.setBounds(new Rectangle(105, 45, 346, 16));
		}
		return ProgressBar;
	}

	/**
	 * This method initializes jPanel1	
	 * 	
	 * @return javax.swing.JPanel	
	 */
	private JPanel getJPanel1() {
		if (jPanel1 == null) {
			jPanel1 = new JPanel();
			jPanel1.setLayout(null);
			jPanel1.setBorder(BorderFactory.createEmptyBorder(0, 0, 0, 0));
			jPanel1.setName("Detail");
			jPanel1.add(getJPanel2(), null);
			jPanel1.add(getJScrollPane(), null);
			jPanel1.add(getJScrollPane1(), null);
		}
		return jPanel1;
	}

	/**
	 * This method initializes jPanel2	
	 * 	
	 * @return javax.swing.JPanel	
	 */
	private JPanel getJPanel2() {
		if (jPanel2 == null) {
			FileLinesComment = new JLabel();
			FileLinesComment.setBounds(new Rectangle(120, 105, 91, 16));
			FileLinesComment.setHorizontalTextPosition(SwingConstants.RIGHT);
			FileLinesComment.setHorizontalAlignment(SwingConstants.RIGHT);
			FileLinesComment.setToolTipText("The number of lines devoted to Java Doc comments.");
			FileLinesComment.setText("0");
			jLabel10 = new JLabel();
			jLabel10.setBounds(new Rectangle(15, 45, 76, 16));
			jLabel10.setText("Characters:");
			FilesLinesCode = new JLabel();
			FilesLinesCode.setBounds(new Rectangle(105, 90, 106, 16));
			FilesLinesCode.setHorizontalTextPosition(SwingConstants.RIGHT);
			FilesLinesCode.setHorizontalAlignment(SwingConstants.RIGHT);
			FilesLinesCode.setToolTipText("The number of lines of code (everything that's not whitespace and isn't a comment line).");
			FilesLinesCode.setText("0");
			jLabel8 = new JLabel();
			jLabel8.setBounds(new Rectangle(15, 60, 61, 16));
			jLabel8.setText("Imports:");
			FileLines = new JLabel();
			FileLines.setBounds(new Rectangle(135, 75, 76, 16));
			FileLines.setHorizontalTextPosition(SwingConstants.RIGHT);
			FileLines.setHorizontalAlignment(SwingConstants.RIGHT);
			FileLines.setToolTipText("The number of lines in the file.");
			FileLines.setText("0");
			NumImports = new JLabel();
			NumImports.setBounds(new Rectangle(105, 60, 106, 16));
			NumImports.setHorizontalTextPosition(SwingConstants.RIGHT);
			NumImports.setHorizontalAlignment(SwingConstants.RIGHT);
			NumImports.setToolTipText("The number of imports in the file.");
			NumImports.setText("0");
			NumCharacters = new JLabel();
			NumCharacters.setBounds(new Rectangle(120, 45, 91, 16));
			NumCharacters.setHorizontalAlignment(SwingConstants.RIGHT);
			NumCharacters.setHorizontalTextPosition(SwingConstants.RIGHT);
			NumCharacters.setToolTipText("The total number of lines in the file.");
			NumCharacters.setText("0");
			FileSize = new JLabel();
			FileSize.setBounds(new Rectangle(90, 30, 121, 16));
			FileSize.setHorizontalAlignment(SwingConstants.RIGHT);
			FileSize.setHorizontalTextPosition(SwingConstants.RIGHT);
			FileSize.setToolTipText("The file's size on disk.");
			FileSize.setText("0B");
			FileName = new JLabel();
			FileName.setBounds(new Rectangle(60, 15, 151, 16));
			FileName.setHorizontalTextPosition(SwingConstants.RIGHT);
			FileName.setHorizontalAlignment(SwingConstants.RIGHT);
			FileName.setToolTipText("No File is currently Selected.  Try selecting a file or scanning a project.");
			FileName.setText("No File Selected");
			jLabel5 = new JLabel();
			jLabel5.setBounds(new Rectangle(30, 105, 76, 16));
			jLabel5.setText("Comments:");
			jLabel4 = new JLabel();
			jLabel4.setBounds(new Rectangle(30, 90, 46, 16));
			jLabel4.setText("Code:");
			jLabel3 = new JLabel();
			jLabel3.setBounds(new Rectangle(15, 75, 38, 15));
			jLabel3.setText("Lines:");
			jLabel2 = new JLabel();
			jLabel2.setBounds(new Rectangle(15, 30, 46, 16));
			jLabel2.setText("Size:");
			jLabel1 = new JLabel();
			jLabel1.setText("File:");
			jLabel1.setBounds(new Rectangle(15, 15, 31, 16));
			jPanel2 = new JPanel();
			jPanel2.setLayout(null);
			jPanel2.setBounds(new Rectangle(195, 15, 226, 136));
			jPanel2.setBorder(BorderFactory.createTitledBorder(null, "File Details", TitledBorder.DEFAULT_JUSTIFICATION, TitledBorder.DEFAULT_POSITION, null, null));
			jPanel2.add(jLabel1, null);
			jPanel2.add(jLabel2, null);
			jPanel2.add(jLabel3, null);
			jPanel2.add(jLabel4, null);
			jPanel2.add(jLabel5, null);
			jPanel2.add(FileName, null);
			jPanel2.add(FileSize, null);
			jPanel2.add(NumCharacters, null);
			jPanel2.add(NumImports, null);
			jPanel2.add(FileLines, null);
			jPanel2.add(jLabel8, null);
			jPanel2.add(FilesLinesCode, null);
			jPanel2.add(jLabel10, null);
			jPanel2.add(FileLinesComment, null);
		}
		return jPanel2;
	}

	/**
	 * This method initializes jScrollPane	
	 * 	
	 * @return javax.swing.JScrollPane	
	 */
	private JScrollPane getJScrollPane() {
		if (jScrollPane == null) {
			jScrollPane = new JScrollPane();
			jScrollPane.setBounds(new Rectangle(15, 15, 166, 136));
			jScrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
			jScrollPane.setViewportView(getFileList());
		}
		return jScrollPane;
	}

	/**
	 * This method initializes FileList	
	 * 	
	 * @return javax.swing.JList	
	 */
	JList getFileList() {
		if (FileList == null) {
			FileList = new JList();
			FileList
					.addListSelectionListener(
							new javax.swing.event.ListSelectionListener() {
						public void valueChanged(
								javax.swing.event.ListSelectionEvent e) { 
							try {
								ListValueSelected((ListFile)
										FileList.getSelectedValue());								
							}catch (NullPointerException e1) {
								
							}
							
						}
					});
		}
		return FileList;
	}
	
	private void ListValueSelected(ListFile ls) {
		FileName.setText(ls.toString());
		FileSize.setText(Long.toString(ls.getFile().length())+"B");
		//FileLines.setText(Integer.toString(FileInfo.getLines(ls.getFile())));
		FileLines.setText(Integer.toString(ProjectDirectory.getFile(
				ls.getFile()).getLinesTotal()));
		// TODO: Everything
		//FilesLinesCode.setText(Integer.toString(FileInfo.getCodeLines(
		//		ls.getFile())));
		FilesLinesCode.setText(Integer.toString(ProjectDirectory.getFile(
				ls.getFile()).getLinesCode()));
		//FileLinesComment.setText(Integer.toString(FileInfo.getCommentLines(
		//		ls.getFile())));
		FileLinesComment.setText(Integer.toString(ProjectDirectory.getFile(
				ls.getFile()).getLinesJavadoc()));
		// this bit is really cool 'cause it sets the whole document to be
		// whatever is in the file without my having to do it manually!
		try {
			FilePreview.read(new FileInputStream(ls.getFile()), null);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * This method initializes jScrollPane1	
	 * 	
	 * @return javax.swing.JScrollPane	
	 */
	private JScrollPane getJScrollPane1() {
		if (jScrollPane1 == null) {
			jScrollPane1 = new JScrollPane();
			jScrollPane1.setBounds(new Rectangle(15, 165, 406, 203));
			jScrollPane1.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
			jScrollPane1.setViewportView(getFilePreview());
			jScrollPane1.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		}
		return jScrollPane1;
	}

	/**
	 * This method initializes FilePreview	
	 * 	
	 * @return javax.swing.JEditorPane	
	 */
	private JEditorPane getFilePreview() {
		if (FilePreview == null) {
			FilePreview = new JEditorPane();
			FilePreview.setEditable(false);
		}
		return FilePreview;
	}

	/**
	 * This method initializes jTabbedPane	
	 * 	
	 * @return javax.swing.JTabbedPane	
	 */
	private JTabbedPane getJTabbedPane() {
		if (jTabbedPane == null) {
			jTabbedPane = new JTabbedPane();
			jTabbedPane.setBounds(new Rectangle(15, 75, 440, 417));
			jTabbedPane.addTab("Overview", null, getJPanel3(), null);
			jTabbedPane.addTab("Detail", null, getJPanel1(), null);
		}
		return jTabbedPane;
	}

	/**
	 * This method initializes jPanel3	
	 * 	
	 * @return javax.swing.JPanel	
	 */
	private JPanel getJPanel3() {
		if (jPanel3 == null) {
			WhitespaceLines = new JLabel();
			WhitespaceLines.setBounds(new Rectangle(135, 135, 271, 16));
			WhitespaceLines.setHorizontalAlignment(SwingConstants.RIGHT);
			WhitespaceLines.setHorizontalTextPosition(SwingConstants.RIGHT);
			WhitespaceLines.setText("No Data");
			CodeLines = new JLabel();
			CodeLines.setBounds(new Rectangle(105, 120, 301, 16));
			CodeLines.setHorizontalAlignment(SwingConstants.RIGHT);
			CodeLines.setHorizontalTextPosition(SwingConstants.RIGHT);
			CodeLines.setText("No Data");
			JavadocLines = new JLabel();
			JavadocLines.setBounds(new Rectangle(165, 105, 241, 16));
			JavadocLines.setHorizontalAlignment(SwingConstants.RIGHT);
			JavadocLines.setHorizontalTextPosition(SwingConstants.RIGHT);
			JavadocLines.setText("No Data");
			TotalLinesCode = new JLabel();
			TotalLinesCode.setBounds(new Rectangle(135, 90, 271, 16));
			TotalLinesCode.setHorizontalAlignment(SwingConstants.RIGHT);
			TotalLinesCode.setHorizontalTextPosition(SwingConstants.RIGHT);
			TotalLinesCode.setText("No Data");
			MinFilesDir = new JLabel();
			MinFilesDir.setBounds(new Rectangle(150, 75, 256, 16));
			MinFilesDir.setHorizontalAlignment(SwingConstants.RIGHT);
			MinFilesDir.setHorizontalTextPosition(SwingConstants.RIGHT);
			MinFilesDir.setText("No Data");
			MaxFilesDir = new JLabel();
			MaxFilesDir.setBounds(new Rectangle(150, 60, 256, 16));
			MaxFilesDir.setHorizontalAlignment(SwingConstants.RIGHT);
			MaxFilesDir.setHorizontalTextPosition(SwingConstants.RIGHT);
			MaxFilesDir.setText("No Data");
			jLabel19 = new JLabel();
			jLabel19.setBounds(new Rectangle(30, 135, 187, 16));
			jLabel19.setText("Whitespace Lines:");
			jLabel18 = new JLabel();
			jLabel18.setBounds(new Rectangle(30, 120, 197, 16));
			jLabel18.setText("Code Lines:");
			jLabel17 = new JLabel();
			jLabel17.setBounds(new Rectangle(30, 105, 214, 15));
			jLabel17.setText("Javadoc Comment Lines:");
			jLabel16 = new JLabel();
			jLabel16.setBounds(new Rectangle(15, 90, 194, 16));
			jLabel16.setText("Total Lines of Code:");
			jLabel15 = new JLabel();
			jLabel15.setBounds(new Rectangle(15, 75, 213, 16));
			jLabel15.setText("Min Files per Directory:");
			jLabel14 = new JLabel();
			jLabel14.setBounds(new Rectangle(15, 60, 220, 16));
			jLabel14.setText("Max Files per Directory:");
			MeanFilesDir = new JLabel();
			MeanFilesDir.setBounds(new Rectangle(150, 45, 256, 16));
			MeanFilesDir.setHorizontalAlignment(SwingConstants.RIGHT);
			MeanFilesDir.setHorizontalTextPosition(SwingConstants.RIGHT);
			MeanFilesDir.setText("No Data");
			jLabel12 = new JLabel();
			jLabel12.setBounds(new Rectangle(15, 45, 227, 16));
			jLabel12.setText("Mean Files per Directory:");
			NumDirectories = new JLabel();
			NumDirectories.setBounds(new Rectangle(135, 30, 271, 16));
			NumDirectories.setHorizontalAlignment(SwingConstants.RIGHT);
			NumDirectories.setHorizontalTextPosition(SwingConstants.RIGHT);
			NumDirectories.setText("No Data");
			jLabel9 = new JLabel();
			jLabel9.setBounds(new Rectangle(15, 30, 206, 16));
			jLabel9.setText("Number of Directories:");
			NumFiles = new JLabel();
			NumFiles.setText("No Data");
			NumFiles.setHorizontalTextPosition(SwingConstants.RIGHT);
			NumFiles.setBounds(new Rectangle(120, 15, 286, 16));
			NumFiles.setHorizontalAlignment(SwingConstants.RIGHT);
			jLabel6 = new JLabel();
			jLabel6.setText("Number of Files:");
			jLabel6.setHorizontalTextPosition(SwingConstants.LEFT);
			jLabel6.setBounds(new Rectangle(15, 15, 170, 16));
			jLabel6.setHorizontalAlignment(SwingConstants.LEFT);
			jPanel3 = new JPanel();
			jPanel3.setLayout(null);
			jPanel3.add(jLabel6, null);
			jPanel3.add(NumFiles, null);
			jPanel3.add(jLabel9, null);
			jPanel3.add(NumDirectories, null);
			jPanel3.add(jLabel12, null);
			jPanel3.add(MeanFilesDir, null);
			jPanel3.add(jLabel14, null);
			jPanel3.add(jLabel15, null);
			jPanel3.add(jLabel16, null);
			jPanel3.add(jLabel17, null);
			jPanel3.add(jLabel18, null);
			jPanel3.add(jLabel19, null);
			jPanel3.add(MaxFilesDir, null);
			jPanel3.add(MinFilesDir, null);
			jPanel3.add(TotalLinesCode, null);
			jPanel3.add(JavadocLines, null);
			jPanel3.add(CodeLines, null);
			jPanel3.add(WhitespaceLines, null);
			jPanel3.add(getJScrollPane2(), null);
		}
		return jPanel3;
	}

	/**
	 * This method initializes jScrollPane2	
	 * 	
	 * @return javax.swing.JScrollPane	
	 */
	private JScrollPane getJScrollPane2() {
		if (jScrollPane2 == null) {
			jScrollPane2 = new JScrollPane();
			jScrollPane2.setBounds(new Rectangle(15, 165, 391, 196));
			jScrollPane2.setViewportView(getDetailTable());
		}
		return jScrollPane2;
	}

	/**
	 * This method initializes DetailTable	
	 * 	
	 * @return javax.swing.JTable	
	 */
	public JTable getDetailTable() {
		if (DetailTable == null) {
			TableColumn tableColumn3 = new TableColumn();
			tableColumn3.setHeaderValue("Lines");
			tableColumn3.setModelIndex(3);
			TableColumn tableColumn2 = new TableColumn();
			tableColumn2.setHeaderValue("Z-Score");
			tableColumn2.setModelIndex(2);
			TableColumn tableColumn1 = new TableColumn();
			tableColumn1.setHeaderValue("Files");
			tableColumn1.setModelIndex(1);
			TableColumn tableColumn = new TableColumn();
			tableColumn.setHeaderValue("Directory");
			DetailTable = new JTable();
			DetailTable.setAutoCreateColumnsFromModel(false);
			DetailTable.addColumn(tableColumn);
			DetailTable.addColumn(tableColumn1);
			DetailTable.addColumn(tableColumn2);
			DetailTable.addColumn(tableColumn3);
		}
		return DetailTable;
	}
	
	public void setDetailTable(JTable jt) {
		DetailTable=jt;
	}
	
	public void setTotalLinesCode(Long Lines) {
		TotalLinesCode.setText(Lines.toString());
	}
	
	public void setTotalJavadocCommentLines(Long Lines) {
		JavadocLines.setText(Lines.toString());
	}
	
	public void setTotalCodeLines(Long Lines) {
		CodeLines.setText(Lines.toString());
	}
	
	public void setTotalWhitespaceLines(Long Lines) {
		WhitespaceLines.setText(Lines.toString());
	}
	
	public void setTotalNumFiles(Long Num) {
		NumFiles.setText(Num.toString());
	}
	
	public void setTotalNumDirectories(Long Num) {
		NumDirectories.setText(Num.toString());
	}
	
	public void setMeanFilesPerDirectory(Float Numf) {
		MeanFilesDir.setText(Numf.toString());
	}
	
	public void setMaxFilesPerDirectory(Long Num) {
		MaxFilesDir.setText(Num.toString());
	}
	
	public void setMinFilesPerDirectory(Long Num) {
		MinFilesDir.setText(Num.toString());
	}

}  //  @jve:decl-index=0:visual-constraint="11,6"
