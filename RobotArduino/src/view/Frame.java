package view;

import java.awt.Color;
import view.Panel;
import java.awt.event.KeyListener;
import java.io.IOException;

import javax.swing.JFrame;

import controller.UserChoice;
import controller.Controller;

import java.awt.BorderLayout;
import java.awt.event.KeyEvent;

public class Frame extends JFrame implements KeyListener {
	private static final long serialVersionUID = 1L;
	private Panel panel;
	private Controller controller;

	public Frame() {
		controller = new Controller();
		panel = new Panel();

		this.setTitle("Robot control");
		this.setSize(400, 325);

		this.setLocationRelativeTo(null);
		this.setBackground(Color.GRAY);
		this.setAlwaysOnTop(true);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);

		panel.setLayout(new BorderLayout());
		this.setContentPane(panel);
		addKeyListener(this);

	}

	@Override
	public void keyPressed(KeyEvent key) {
		switch (key.getKeyCode()) {
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
