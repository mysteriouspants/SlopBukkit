/*
 *  ListFile.java - Source Scope Extended Object for Swing Display
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

public class ListFile {

	private File f;
	
	public ListFile(File f) {
		this.f=f;
	}
	
	public File getFile() { return f; }
	
	public String toString() { return f.getName(); }
	
}
