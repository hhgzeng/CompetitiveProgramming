import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Race extends Frame {
    private final int TRACK_LENGTH = 800;
    private Animal turtle;
    private Animal rabbit;
    private Animal mouse;
    
    public String[] rank = {"", "", ""};
    public int[] times = {0, 0, 0};
    public int pos = 0;
    Image image;

    public Race() {
        setTitle("Animals Race");
        setVisible(true);
        setLocation(300, 300);
        setSize(1000, 430);
        addWindowListener(new WindowAdapter() {  // 关闭窗口监听
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        RacePanel racePanel = new RacePanel();
        add(racePanel);

        turtle = new Animal("Turtle", 15, racePanel);
        rabbit = new Animal("Rabbit", 30, racePanel);
        mouse = new Animal("Mouse", 25, racePanel);

        Thread turtleThread = new Thread(turtle);
        Thread rabbitThread = new Thread(rabbit);
        Thread mouseThread = new Thread(mouse);

        int select = JOptionPane.showConfirmDialog(null, "Please confirm if the race has started?", "Race", JOptionPane.YES_NO_OPTION);
        if (select == JOptionPane.YES_OPTION) {
            turtleThread.start();
            rabbitThread.start();
            mouseThread.start();
            System.out.println("Race begins!");
        } else {
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        new Race();
    }

    class RacePanel extends Panel {
        @Override  // 图形界面，展示赛跑过程
        public void paint(Graphics g) {
            // 调用父类方法paint，保留父类原有的绘画行为
            super.paint(g);
            image = Toolkit.getDefaultToolkit().getImage("/Users/jingzeng/Desktop/VSCode/Java/JavaHomework/turtle.jpg");
            g.drawImage(image, turtle.position, 20, 100, 100, this);
            image = Toolkit.getDefaultToolkit().getImage("/Users/jingzeng/Desktop/VSCode/Java/JavaHomework/rabbit.jpg");
            g.drawImage(image, rabbit.position, 150, 100, 100, this);
            image = Toolkit.getDefaultToolkit().getImage("/Users/jingzeng/Desktop/VSCode/Java/JavaHomework/mouse.jpg");
            g.drawImage(image, mouse.position, 280, 100, 100, this);
        }
    }

    class Animal implements Runnable {
        private String name;
        private int speed;
        private int position;
        private int time;
        private Panel panel;

        public Animal(String name, int speed, Panel panel) {
            this.name = name;
            this.speed = speed;
            this.panel = panel;
            this.position = 100;
            this.time = 0;
        }

        @Override
        public void run() {
            while (position < TRACK_LENGTH) {
                // 线程休眠时间
                try {
                    int sleeptime = (int)(Math.random() * 100) + 100;
                    time += sleeptime;
                    Thread.sleep(sleeptime);
                } catch (Exception e) {
                    System.out.println(e);
                }

                // 动物赛跑随机休息
                if (name == "Rabbit") {
                    int random = (int)(Math.random() * 100);
                    if (random <= 40) {
                        System.out.println("Rabbit rests for a while!");
                        continue;
                    }
                } else if (name == "Mouse") {
                    int random = (int)(Math.random() * 100);
                    if (random <= 30) {
                        System.out.println("Mouse rests for a while!");
                        continue;
                    }
                } else {
                    int random = (int)(Math.random() * 100);
                    if (random <= 10) {
                        System.out.println("Turtle rests for a while!");
                        continue;
                    }
                }
                position += speed;
                position = Math.min(position, TRACK_LENGTH);
                panel.repaint();
            }
            
            // 输出比赛结果
            System.out.println(name + " finished the race!");
            times[pos] = time;
            rank[pos++] = name;
            if (pos == 3) {
                System.out.println("Race ends!");
                System.out.println();
                System.out.println("The final result is as follows: ");
                System.out.println("First place: " + rank[0] + ", Time: " + times[0] / 1000.0 + "s");
                System.out.println("Second place: " + rank[1] + ", Time: " + times[1] / 1000.0 + "s");
                System.out.println("Third place: " + rank[2] + ", Time: " + times[2] / 1000.0 + "s");
                if (pos == 3) {
                    JOptionPane.showConfirmDialog(null, "The final result is as follows: \n" + 
                    "First place: " + rank[0] + ", Time: " + times[0] / 1000.0 + "s\n" + 
                    "Second place: " + rank[1] + ", Time: " + times[1] / 1000.0 + "s\n" + 
                    "Third place: " + rank[2] + ", Time: " + times[2] / 1000.0 + "s\n" + 
                    "Please press any key to exit!",
                    "Race ends!", JOptionPane.YES_NO_OPTION);
                    System.exit(0);
                }
            }
        }
    }
}