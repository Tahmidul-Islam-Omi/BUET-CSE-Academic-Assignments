import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.List;
import java.util.ArrayList;

// ConcreteSubject Class
class GenreNotifier implements Subject {
    private String genreName;
    private List<Observer> subscribers;
    private ExecutorService executor;

    public GenreNotifier(String genreName) {
        this.genreName = genreName;
        this.subscribers = new ArrayList<>();
        this.executor = Executors.newCachedThreadPool();
    }

    public void addSubscriber(Observer subscriber) {
        if (!subscribers.contains(subscriber)) {
            subscribers.add(subscriber);
        }
    }

    public void removeSubscriber(Observer subscriber) {
        subscribers.remove(subscriber);
    }

    public void notifySubscribers(String movie) {
        for (Observer subscriber : subscribers) {
            executor.submit(() -> {
                subscriber.update(genreName, movie);
            });
        }
    }

    public void shutdownNotifier() {
        executor.shutdown();
    }
}
