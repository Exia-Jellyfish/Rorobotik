package view;

import java.awt.Graphics;
import java.awt.Image;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

public class Panel extends JPanel {


public Panel(){
	
}
	public void paintComponent(Graphics g){
		try{
			Image kbd = ImageIO.read(new File("arrowkeys.png"));
			g.drawImage(kbd,  78, 70, this);
		
		}	catch (IOException e) {
			e.printStackTrace();
		}
	}
}
