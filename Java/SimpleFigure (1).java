// Draws and fills shapes in different colors.

import java.awt.*;

public class SimpleFigure{
    public static void main(String[] args) {
        DrawingPanel panel = new DrawingPanel(250, 200);
        panel.setBackground(Color.YELLOW);

        Graphics g = panel.getGraphics();
		
		g.setColor(Color.GREEN);
		g.fillRect(10, 20, 200, 160);
		g.setColor(Color.RED);
		g.fillOval(10, 20, 100, 80); // circle
        g.fillOval(110, 100, 100, 80);
		g.setColor(Color.BLACK);
		g.drawLine(10, 60, 110, 60);
		g.drawLine(60, 20, 60, 100);
		g.drawLine(110, 140, 210, 140);
		g.drawLine(160, 100, 160, 180);
    }
}
