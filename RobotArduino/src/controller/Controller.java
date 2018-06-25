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

			break;

		case FORWARD:

			break;

		case UTURN:

			break;

		default:
			break;

		}
	}

	public UserChoice getUserChoice() {
		return userChoice;
	}

	public void setUserChoice(UserChoice userChoice) {
		this.userChoice = userChoice;
	}
}
