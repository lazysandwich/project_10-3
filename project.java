package com.company;


import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("my game");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setExtendedState(JFrame.MAXIMIZED_BOTH);
        frame.setUndecorated(true);
        frame.setVisible(true);
        frame.add(new Main());
    }
}
