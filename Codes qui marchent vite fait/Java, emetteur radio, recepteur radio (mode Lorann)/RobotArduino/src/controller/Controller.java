package controller;

import java.io.IOException;

public class Controller {
	public static String messageString;
	private UserChoice userChoice;
    ArduinoConnector ardui;
    public Controller() {
	    this.ardui	= new ArduinoConnector();
	}

	public void movement() throws IOException {
		switch (userChoice) {

		case RIGHT:
			messageString = "e";

			break;
		case LEFT:
			messageString = "w";
			break;

		case FORWARD:
			messageString = "n";
			break;

		case UTURN:
			messageString = "s";
			break;

		default:
			break;

		}
		ardui.sendToArduino(messageString);

	}

	public UserChoice getUserChoice() {
		return userChoice;
	}

	public void setUserChoice(UserChoice userChoice) {
		this.userChoice = userChoice;
	}
}
