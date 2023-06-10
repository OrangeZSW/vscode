
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.QuadCurve2D;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * 在窗口中绘制爱心
 * * @author: orange
 * orange
 */
public class Heart extends JPanel {

    private static final long serialVersionUID = 1L;

    public void paint(Graphics g) {
        Graphics2D g2 = (Graphics2D) g;
        g2.setColor(Color.RED);
        g2.setStroke(new BasicStroke(2.0f));
        QuadCurve2D q = new QuadCurve2D.Float();
        q.setCurve(100, 100, 150, 10, 200, 100);
        g2.draw(q);
        q.setCurve(200, 100, 250, 190, 300, 100);
        g2.draw(q);
        g2.fillOval(130, 100, 40, 40);
        g2.fillOval(230, 100, 40, 40);
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame();
        frame.add(new Heart());
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}