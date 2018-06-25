package controller;

import java.io.IOException;

public class Controller {
	public static String messageString;
	private UserChoice userChoice;

	public Controller() {
	}

	public void movement() throws IOException {
		switch (userChoice) {

		case RIGHT:
			messageString = "r";

			break;
		case LEFT:
			messageString = "l";
			break;

		case FORWARD:
			messageString = "f";
			break;

		case UTURN:
			messageString = "u";
			break;

		default:
			break;

		}
		System.out.println(messageString);
	}

	public UserChoice getUserChoice() {
		return userChoice;
	}

	public void setUserChoice(UserChoice userChoice) {
		this.userChoice = userChoice;
	}
}
