// Draws and fills shapes in different colors.

import java.awt.*;

public class SimpleFigure{
    public static void main(String[] args) {
        DrawingPanel panel = new DrawingPanel(1000, 1000);
        panel.setBackground(Color.CYAN);

        Graphics g = panel.getGraphics();
		
		g.drawOval(50, 25, 20, 20); // circle
        g.drawRect(150, 10, 40, 20);
        g.drawOval(50, 25, 20, 20);
        g.setColor(Color.WHITE);
        g.fillOval(150, 50, 40, 20);
        g.fillRect(25, 50, 20, 20);
		while(true){
			drawOrbitingSphere(10, g);
		}
    }
	public static void orbit(Graphics g, int range, int x, int y, int size){
		// formula (x-0)^2+(y-0)^2=6^2
		g.drawOval()
	}
}
