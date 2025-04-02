// Subject Interface
public interface Subject {
    void addSubscriber(Observer subscriber);
    void removeSubscriber(Observer subscriber);
    void notifySubscribers(String movie);
}
