/*
 *  Directory.java - Source Scope Directory Node
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
import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

public class Directory implements Comparable {

	private File me;
	private TreeSet<SourceFile> SourceFiles=new TreeSet<SourceFile>();
	private TreeSet<Directory> ChildDirectories=new TreeSet<Directory>();
	private boolean hasQuickScanned=false;
	private boolean hasDeepScanned=false;
	
	private Directory() { }
	public Directory(File f) {
		me=f;
	}
	
	public File getFile() { return me; }
	
	public void QuickScan() {
		if(hasQuickScanned) return;
		Directory d;
		for(File f:me.listFiles()) {
			if(f.isDirectory()) {
				d=new Directory(f);
				if(".svn".equals(f.getName()))
					continue;
				else if(".cvs".equals(f.getName()))
					continue;
				else if(".rcs".equals(f.getName()))
					continue;
				d.QuickScan();
				ChildDirectories.add(d);
				
			}
			else if(f.getName().endsWith(".java")) {
				SourceFiles.add(new SourceFile(f));
			}
		}
		hasQuickScanned=true;
	}
	
	public void DeepScan() {
		DeepScan(true);
	}
	
	public void DeepScan(boolean recursive) {
		for(SourceFile f:SourceFiles)
			f.Scan();
		hasDeepScanned=true;
		if(!recursive) return;
		for(Directory d:ChildDirectories)
			d.DeepScan();
	}
	
	public long getNumDirectories() {
		if(!hasQuickScanned) QuickScan();
		long NumDirs=1;
		for(Directory d:ChildDirectories) {
			NumDirs+=d.getNumDirectories();
		}
		return NumDirs;
	}
	
	public long getNumFiles() {
		if(!hasQuickScanned) QuickScan();
		long NumFiles=SourceFiles.size();
		for(Directory d:ChildDirectories) {
			NumFiles+=d.getNumFiles();
		}
		return NumFiles;
	}
	
	public int getNumLocalFiles() {
		if(!hasQuickScanned) QuickScan();
		return SourceFiles.size();
	}
	
	public int getNumLocalDirectories() {
		if(!hasQuickScanned) QuickScan();
		return ChildDirectories.size();
	}
	
	public long getNumLocalLines() {
		if(!hasDeepScanned)
			DeepScan(false);
		long Lines=0;
		for(SourceFile sf:SourceFiles)
			Lines+=sf.getLinesTotal();
		return Lines;
	}
	
	public long getNumLines() {
		if(!hasDeepScanned)
			DeepScan(true);
		long Lines=getNumLocalLines();
		for(Directory d:ChildDirectories)
			Lines+=d.getNumLines();
		return Lines;
	}
	
	public long getNumLocalJavadoc() {
		if(!hasDeepScanned)
			DeepScan(false);
		long Lines=0;
		for(SourceFile sf:SourceFiles)
			Lines+=sf.getLinesJavadoc();
		return Lines;
	}
	
	public long getNumJavadoc() {
		if(!hasDeepScanned)
			DeepScan(true);
		long Lines=getNumLocalJavadoc();
		for(Directory d:ChildDirectories)
			Lines+=d.getNumJavadoc();
		return Lines;
	}
	
	public long getNumWhitespace() {
		if(!hasDeepScanned)
			DeepScan(true);
		long Lines=getNumLocalWhitespace();
		for(Directory d:ChildDirectories)
			Lines+=d.getNumWhitespace();
		return Lines;
	}
	
	public long getNumLocalWhitespace() {
		if(!hasDeepScanned)
			DeepScan(false);
		long Lines=0;
		for(SourceFile sf:SourceFiles)
			Lines+=sf.getLinesWhitespace();
		return Lines;
	}
	
	public long getNumCodeLines( ) {
		if(!hasDeepScanned)
			DeepScan(false);
		long Lines=getNumLocalCodeLines();
		for(Directory d:ChildDirectories)
			Lines+=d.getNumCodeLines();
		return Lines;
	}
	
	public long getNumLocalCodeLines() {
		if(!hasDeepScanned)
			DeepScan(false);
		long Lines=0;
		for(SourceFile sf:SourceFiles)
			Lines+=sf.getLinesCode();
		return Lines;
	}
	
	public Set<SourceFile> getLocalFiles() {
		return SourceFiles;
	}
	
	public Set<Directory> getLocalChildDirectories(){
		return ChildDirectories;
	}
	
	public Set<SourceFile> getFiles() {
		TreeSet<SourceFile> ts=new TreeSet<SourceFile>();
		ts.addAll(SourceFiles);
		for(Directory d:ChildDirectories)
			ts.addAll(d.getFiles());
		return ts;
	}
	
	public Set<Directory> getDirectories() {
		TreeSet<Directory> ts=new TreeSet<Directory>();
		ts.addAll(ChildDirectories);
		for(Directory d:ChildDirectories)
			ts.addAll(d.getDirectories());
		return ts;
	}
	
	public float getMeanFilesDirectory() {
		return getNumFiles()/getNumDirectories();
	}
	
	public long getMaxFilesDirectory() {
		Iterator<Directory> dirs=getDirectories().iterator();
		Directory max=this;
		Directory temp=null;
		while(dirs.hasNext()) {
			temp=dirs.next();
			if(temp.getNumLocalFiles()>max.getNumLocalFiles())
				max=temp;
		}
		return max.getNumLocalFiles();
	}
	
	public long getMinFilesDirectory() {
		Iterator<Directory> dirs=getDirectories().iterator();
		Directory min=this;
		Directory temp=null;
		while(dirs.hasNext()) {
			temp=dirs.next();
			if(temp.getNumLocalFiles()<min.getNumLocalFiles())
				min=temp;
		}
		return min.getNumLocalFiles();
	}
	
	public SourceFile getFile(File f) {
		SourceFile sf=getLocalFile(f);
		if(sf!=null)
			return sf;
		else {
			sf=getFileInChildDirectory(f);
			if(sf!=null)
				return sf;
		}
		return null;
	}
	
	public SourceFile getLocalFile(File f) {
		for(SourceFile sf:SourceFiles)
			if(sf.getFile().compareTo(f)==0)
				return sf;
		return null;
	}
	
	public SourceFile getFileInChildDirectory(File f) {
		SourceFile sf;
		for(Directory d:ChildDirectories) {
			sf=d.getFile(f);
			if(sf!=null)
				return sf;
		}
		return null;
	}
	
	public String toString() {
		return toStringHelper("");
	}
	
	private String toStringHelper(String ident) {
		StringBuilder sb=new StringBuilder();
		sb.append(ident+getFile().getAbsolutePath()+"\n");
		sb.append(ident+" Directories: "+getNumLocalDirectories()+"\n");
		sb.append(ident+" Files:       "+getNumLocalFiles()+"\n");
		sb.append(ident+" Lines Code:  "+getNumLocalLines()+"\n");
		for(Directory d:ChildDirectories) {
			sb.append(d.toStringHelper(ident+" "));
		}
		return sb.toString();
	}
	public int compareTo(Object o) {
		return me.hashCode()-o.hashCode();
	}
	
}
