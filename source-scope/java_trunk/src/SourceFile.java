/*
 *  SourceFile.java - Source Scope Source File Node
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

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class SourceFile implements Comparable {
	
	private File me;

	private long FileSize=0;
	private long Characters=0;
	private int LinesTotal=0;
	private int LinesCode=0;
	private int LinesJavadoc=0;
	private int LinesWhitespace=0;
	
	private SourceFile() { }
	public SourceFile(File f) {
		me=f;
	}
	
	public File getFile() { return me; }
	
	public void Scan() {
		if(!me.getName().endsWith(".java"))
			return;
		FileInputStream fstream;
		try {
			fstream=new FileInputStream(me);
		} catch (FileNotFoundException e) {
			System.err.println("SourceFile.java failed to open file "+
					me.getName()+".");
			return;
		}
		StringBuilder sb; String str; byte CommentMode=0;
		try {
			while(fstream.available()>0) {
				sb=new StringBuilder();
				while((sb.length()==0)?true:sb.charAt(sb.length()-1)!='\n'&&
						fstream.available()>0){
					sb.append(((char) fstream.read()));
					Characters++;
					FileSize+=(Integer.SIZE);
				}
				LinesTotal++;
				str=sb.toString().trim();
				switch(CommentMode){
				case 1: //true
					if(str.contains("*/"))
						CommentMode=0;
					LinesJavadoc++;
					break;
				case 0: //false
				default:
					if("".compareTo(str)==0) {
						LinesWhitespace++;
					}
					else if(str.contains("/**")){
						LinesJavadoc++;
						CommentMode=1;
					}
					else 
						LinesCode++;
					break;
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public long getCharacters() { return Characters; }
	public long getFileSize() { return FileSize; }
	public int getLinesCode() { return LinesCode; }
	public int getLinesJavadoc() { return LinesJavadoc; }
	public int getLinesTotal() { return LinesTotal; }
	public int getLinesWhitespace() { return LinesWhitespace; }
	public int compareTo(Object o) {
		return me.hashCode()-o.hashCode();
	}
	
}
