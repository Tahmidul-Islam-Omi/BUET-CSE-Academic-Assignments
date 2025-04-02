import javax.swing.undo.CompoundEdit;

interface Component {
    double getPrice();

    String getDescription();
}

// Concrete Component representing individual hardware components
class HardwareComponent implements Component {
    private String name;
    private double price;

    public HardwareComponent(String name, double price) {
        this.name = name;
        this.price = price;
    }

    @Override
    public double getPrice() {
        return price;
    }

    @Override
    public String getDescription() {
        return name;
    }
}

// Abstract Decorator class
abstract class Decorator implements Component {
    protected Component component;
    
    public Decorator(Component component) {
        this.component = component;
    }
    
    @Override
    public double getPrice() {
        return component.getPrice();
    }
    
    @Override
    public String getDescription() {
        return component.getDescription();
    }
}

// Concrete Decorators
class WarrantyDecorator extends Decorator {
    public WarrantyDecorator(Component component) {
        super(component);
    }
    
    @Override
    public double getPrice() {
        return super.getPrice() + 50.0; // Warranty costs $50
    }
    
    @Override
    public String getDescription() {
        return super.getDescription() + " + Extended Warranty";
    }
}

class InstallationDecorator extends Decorator {
    public InstallationDecorator(Component component) {
        super(component);
    }
    
    @Override
    public double getPrice() {
        return super.getPrice() + 100.0; // Installation costs $100
    }
    
    @Override
    public String getDescription() {
        return super.getDescription() + " + Installation Service";
    }
}

class PerformanceBoostDecorator extends Decorator {
    public PerformanceBoostDecorator(Component component) {
        super(component);
    }
    
    @Override
    public double getPrice() {
        return super.getPrice() + 150.0; // Performance boost costs $150
    }
    
    @Override
    public String getDescription() {
        return super.getDescription() + " + Performance Boost";
    }
}

public class 2105115 {
    public static void main(String[] args) {
        
        Component cpu = new HardwareComponent("CPU", 300.0);
        
        
        cpu = new WarrantyDecorator(cpu);
        cpu = new InstallationDecorator(cpu);
        
        System.out.println("Configuration: " + cpu.getDescription());
        System.out.println("Total Price: $" + cpu.getPrice());
        
        
        Component gpu = new HardwareComponent("GPU", 500.0);
        gpu = new WarrantyDecorator(gpu);
        gpu = new InstallationDecorator(gpu);
        gpu = new PerformanceBoostDecorator(gpu);
        
        System.out.println("Configuration: " + gpu.getDescription());
        System.out.println("Total Price: $" + gpu.getPrice());
    }
}