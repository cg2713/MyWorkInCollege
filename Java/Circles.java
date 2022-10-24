// This program draws a series of grids with concentric circles using the
// DrawingPanel class.  

import java.awt.*;

public class Circles {
    public static void main(String[] args) {
        DrawingPanel panel = new DrawingPanel(400, 425);
        panel.setBackground(Color.CYAN);
        Graphics g = panel.getGraphics();
        
        drawFigure(g, 0, 0, 1, 100, 10);
        drawFigure(g, 18, 175, 6, 24, 4);
        drawFigure(g, 180, 25, 5, 40, 5);
        drawFigure(g, 180, 250, 4, 36, 6);
    }
    
    public static void drawFigure(Graphics g, int x, int y, int numRowCols,
                                  int size, int numCircles) {
        
        for (int row = 0; row < numRowCols; row++) {
            for (int col = 0; col < numRowCols; col++) {
                drawSubfigure(g, x + size * col, y + size * row, size, 
                              numCircles);
            }
        }
    }
    
    public static void drawSubfigure(Graphics g, int x, int y, int size, 
                                     int numCircles) {
        g.setColor(Color.GREEN);
        g.fillRect(x, y, size, size);
        
        g.setColor(Color.BLACK);
        g.drawRect(x, y, size, size);
        
        g.setColor(Color.YELLOW);
        g.fillOval(x, y, size, size);
        
        g.setColor(Color.BLACK);
        
        // the "+" lines
        g.drawLine(x, y + size / 2, x + size, y + size / 2);
        g.drawLine(x + size / 2, y, x + size / 2, y + size);
        
        // the "X" lines
        g.drawLine(x, y, x + size, y + size);
        g.drawLine(x, y + size, x + size, y);
        
        // concentric circles
        for (int i = 0; i < numCircles; i++) {
            int shift = size * i / numCircles / 2;
            int newSize = size - 2 * shift;
            g.drawOval(x + shift, y + shift, newSize, newSize);
        }
    }
}
