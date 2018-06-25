package view;

import java.awt.Color;
import java.awt.Panel;
import java.awt.event.KeyListener;
import java.io.IOException;

import javax.swing.JFrame;
import javax.swing.JLabel;

import controller.UserChoice;
import controller.Controller;

import java.awt.BorderLayout;
import java.awt.event.KeyEvent;


public class Frame extends JFrame implements KeyListener{
	private static final long serialVersionUID = 1L;
	private Panel panel;
	private JLabel lab;
	private Controller controller;
	
	public Frame() {
		controller = new Controller();
		panel = new Panel();
		lab = new JLabel();
		
		this.setTitle("Robot control");
		this.setSize(400,325);
		this.setVisible(true);
		this.setLocationRelativeTo(null);
		this.setBackground(Color.GRAY);
		this.setAlwaysOnTop(true);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		panel.setLayout(new BorderLayout());
		panel.add(lab,BorderLayout.SOUTH);
		this.setContentPane(panel);
		addKeyListener(this);
		
}
	@Override
	public void keyPressed(KeyEvent key){
		switch (key.getKeyCode())
		{
		case KeyEvent.VK_UP:
			controller.setUserChoice(UserChoice.FORWARD);
			try {
				controller.movement();
			} catch (IOException e) {
				
				e.printStackTrace();
			}
			break;
		
		case KeyEvent.VK_LEFT:
			controller.setUserChoice(UserChoice.LEFT);
			try {
				controller.movement();
			} catch (IOException e) {
				
				e.printStackTrace();
			}
			
			break;
		
		case KeyEvent.VK_RIGHT:			
			controller.setUserChoice(UserChoice.RIGHT);
			try {
				controller.movement();
			} catch (IOException e) {
				
				e.printStackTrace();
			}
			break;
		
		case KeyEvent.VK_DOWN:

			controller.setUserChoice(UserChoice.UTURN);
			try {
				controller.movement();
			} catch (IOException e) {
				
				e.printStackTrace();
			}
			break;
		
		default: 
			break;
			
		}
	}
	@Override
	public void keyReleased(KeyEvent e) {
		
	}
	@Override
	public void keyTyped(KeyEvent e) {
		
	}
}
