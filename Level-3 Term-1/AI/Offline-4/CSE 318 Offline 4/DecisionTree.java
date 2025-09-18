import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Set;

public class DecisionTree {

    public enum GainMetric {
        IG,
        IGR,
        NWIG
    }

    // private static final double MIN_GAIN_THRESHOLD = 0.001; // Minimum gain for
    // split

    public static void main(String[] args) {

        if (args.length != 2) {
            System.err.println("Error: Incorrect number of arguments. Usage: java DecisionTree <criterion> <maxDepth>");
            System.exit(1);
        }

        String criterionStr = args[0].toUpperCase();
        int maxDepth;
        GainMetric metric;

        try {
            metric = GainMetric.valueOf(criterionStr);
            maxDepth = Integer.parseInt(args[1]);
        } catch (IllegalArgumentException e) {
            System.err.println("Error: Invalid criterion or max depth");
            System.exit(1);
            return;
        }

        String datasetPath = "Datasets/Iris.csv";
        // String datasetPath = "Datasets/adult.data";

        try {
            System.out.println("Loading dataset from: " + datasetPath);
            List<String[]> data = loadDataset(datasetPath);

            imputeMissingValues(data);

            if (data.isEmpty()) {
                System.err.println("Dataset is empty");
                System.exit(1);
            }

            int numColumns = data.get(0).length;
            int targetIndex = numColumns - 1; // Last column is the target

            int[] featureIndices = new int[numColumns - 1];
            for (int i = 0; i < featureIndices.length; i++) {
                featureIndices[i] = i;
            }

            int numRuns = 20;
            double testingSplit = 0.2;
            List<Double> accuracies = new ArrayList<>();

            for (int run = 1; run <= numRuns; run++) {
                // Shuffle and split for each run
                List<List<String[]>> splits = splitDataset(data, testingSplit, System.nanoTime());
                List<String[]> trainingData = splits.get(0);
                List<String[]> testingData = splits.get(1);

                System.out.println("\nRun " + run + ":");
                System.out.println("Training data size: " + trainingData.size());
                System.out.println("Testing data size: " + testingData.size());

                System.out.println(
                        "Building decision tree using " + metric + " criterion with max depth " +
                                (maxDepth == 0 ? "no limit" : maxDepth) + "...");

                TreeNode root = buildDecisionTree(trainingData, featureIndices, targetIndex, metric, maxDepth);

                int nodeCount = countNodes(root);
                int actualDepth = calculateActualDepth(root);
                System.out.println("Number of nodes: " + nodeCount);
                System.out.println("Actual depth: " + actualDepth);

                // Evaluate on test set
                System.out.println("Evaluating on test set...");
                double accuracy = evaluateModel(root, testingData, featureIndices, targetIndex);
                System.out.printf("Accuracy: %.2f%%\n", accuracy * 100);
                accuracies.add(accuracy);
            }

            double sum = 0.0;
            for (double acc : accuracies) {
                sum += acc;
            }
            double avgAccuracy = sum / numRuns;
            System.out.printf("\nAverage accuracy over %d runs: %.2f%%\n", numRuns, avgAccuracy * 100);

            System.out.println("Start");
            // Run comprehensive experiments and generate CSV report
            System.out.println("\nRunning comprehensive experiments for all criteria and depths...");
            runComprehensiveExperiments(data, featureIndices, targetIndex, datasetPath);

            System.out.println("End");

        } catch (IOException e) {
            System.err.println("Error loading dataset: " + e.getMessage());
            System.exit(1);
        }
    }

    private static void runComprehensiveExperiments(List<String[]> data, int[] featureIndices, int targetIndex,
            String datasetPath) {
        GainMetric[] criteria = { GainMetric.IG, GainMetric.IGR, GainMetric.NWIG };
        int[] depths = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
        int numRuns = 20;
        double testingSplit = 0.2;

        String csvFileName = "decision_tree_experiments_Iris.csv";

        try (PrintWriter writer = new PrintWriter(new FileWriter(csvFileName))) {
            // Write CSV header
            writer.println("Criteria,MaxDepth,ActualDepth,NodeCount,Accuracy");

            for (GainMetric criterion : criteria) {
                for (int depth : depths) {
                    List<Double> accuracies = new ArrayList<>();
                    List<Integer> nodeCounts = new ArrayList<>();
                    List<Integer> actualDepths = new ArrayList<>();

                    for (int run = 1; run <= numRuns; run++) {
                        // Shuffle and split for each run
                        List<List<String[]>> splits = splitDataset(data, testingSplit, System.nanoTime() + run);
                        List<String[]> trainingData = splits.get(0);
                        List<String[]> testingData = splits.get(1);

                        // Build decision tree
                        TreeNode root = buildDecisionTree(trainingData, featureIndices, targetIndex, criterion, depth);

                        // Count nodes
                        int nodeCount = countNodes(root);
                        nodeCounts.add(nodeCount);

                        // Calculate actual depth
                        int actualDepth = calculateActualDepth(root);
                        actualDepths.add(actualDepth);

                        // Evaluate accuracy
                        double accuracy = evaluateModel(root, testingData, featureIndices, targetIndex);
                        accuracies.add(accuracy);
                    }

                    // Calculate averages using logic
                    double sumAccuracy = 0.0;
                    for (double acc : accuracies) {
                        sumAccuracy += acc;
                    }
                    double avgAccuracy = sumAccuracy / accuracies.size();

                    double sumNodeCount = 0.0;
                    for (int nodeCount : nodeCounts) {
                        sumNodeCount += nodeCount;
                    }
                    int avgNodeCount = (int) Math.round(sumNodeCount / nodeCounts.size());

                    double sumActualDepth = 0.0;
                    for (int actualDepth : actualDepths) {
                        sumActualDepth += actualDepth;
                    }
                    int avgActualDepth = (int) Math.round(sumActualDepth / actualDepths.size());

                    // Write to CSV
                    System.out.printf(
                            "Completed: %s criterion, max depth %d, avg actual depth: %d, avg nodes: %d, avg accuracy: %.4f%n",
                            criterion, depth, avgActualDepth, avgNodeCount, avgAccuracy);
                    writer.printf("%s,%d,%d,%d,%.4f%n", criterion, depth, avgActualDepth, avgNodeCount, avgAccuracy);
                }
            }

        } catch (IOException e) {
            System.err.println("Error writing CSV file: " + e.getMessage());
        }
    }

    private static List<String[]> loadDataset(String filePath) throws IOException {
        List<String[]> data = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            boolean firstLine = true;

            while ((line = br.readLine()) != null) {
                if (firstLine) {
                    firstLine = false;
                    if (isLikelyHeader(line)) {
                        continue;
                    }
                }

                String[] values;
                if (line.contains(",")) {
                    values = line.split(",\\s*");
                    // Skip the first column only for Iris.csv
                    if (filePath.toLowerCase().contains("iris.csv")) {
                        String[] trimmed = new String[values.length - 1];
                        System.arraycopy(values, 1, trimmed, 0, values.length - 1);
                        values = trimmed;
                    }
                } else {
                    values = line.split("\\s+");
                }

                for (int i = 0; i < values.length; i++) {
                    values[i] = values[i].trim();
                }

                int expectedColumns = filePath.toLowerCase().contains("adult.data") ? 15 : values.length;

                if (values.length != expectedColumns) {
                    continue;
                }

                data.add(values);
            }
        }
        return data;
    }

    private static boolean isLikelyHeader(String line) {
        String[] values;
        if (line.contains(",")) {
            values = line.split(",\\s*");
        } else {
            values = line.split("\\s+");
        }

        int numericCount = 0;
        for (String value : values) {
            value = value.trim();
            try {
                Double.parseDouble(value);
                numericCount++;
            } catch (NumberFormatException e) {
                // Not a numeric value
            }
        }

        // If less than half the values are numeric, likely a header
        return numericCount < values.length / 2;
    }

    private static List<List<String[]>> splitDataset(List<String[]> data, double testingRatio, long seed) {
        List<String[]> shuffledData = new ArrayList<>(data);
        Collections.shuffle(shuffledData, new Random(seed));

        int testingSize = (int) Math.round(shuffledData.size() * testingRatio);
        int trainingSize = shuffledData.size() - testingSize;

        List<String[]> trainingData = new ArrayList<>(shuffledData.subList(0, trainingSize));
        List<String[]> testingData = new ArrayList<>(shuffledData.subList(trainingSize, shuffledData.size()));

        List<List<String[]>> result = new ArrayList<>();
        result.add(trainingData);
        result.add(testingData);

        return result;
    }

    private static double calculateEntropy(List<String[]> data, int targetIndex) {
        if (data.isEmpty())
            return 0.0;

        Map<String, Integer> classCounts = new HashMap<>();
        for (String[] row : data) {
            String targetValue = row[targetIndex];
            classCounts.put(targetValue, classCounts.getOrDefault(targetValue, 0) + 1);
        }

        double entropy = 0.0;
        int totalSize = data.size();

        for (int count : classCounts.values()) {
            if (count > 0) {
                double probability = (double) count / totalSize;
                entropy -= probability * (Math.log(probability) / Math.log(2));
            }
        }

        return entropy;
    }

    private static double calculateInformationGain(List<String[]> data, int attributeIndex, int targetIndex) {
        double parentEntropy = calculateEntropy(data, targetIndex);

        Map<String, List<String[]>> attributeGroups = new HashMap<>();
        for (String[] row : data) {
            String attributeValue = row[attributeIndex];

            // attributeGroups.computeIfAbsent(attributeValue, k -> new ArrayList<>()).add(row);

            if (!attributeGroups.containsKey(attributeValue)) {
                attributeGroups.put(attributeValue, new ArrayList<>());
            }
            attributeGroups.get(attributeValue).add(row);
        }

        // Calculate weighted entropy of children
        double weightedEntropy = 0.0;
        int totalSize = data.size();

        for (List<String[]> group : attributeGroups.values()) {
            double weight = (double) group.size() / totalSize;
            weightedEntropy += weight * calculateEntropy(group, targetIndex);
        }

        return parentEntropy - weightedEntropy;
    }

    private static double calculateIntrinsicValue(List<String[]> data, int attributeIndex) {
        Map<String, Integer> valueCounts = new HashMap<>();
        for (String[] row : data) {
            String attributeValue = row[attributeIndex];
            valueCounts.put(attributeValue, valueCounts.getOrDefault(attributeValue, 0) + 1);
        }

        double intrinsicValue = 0.0;
        int totalSize = data.size();

        for (int count : valueCounts.values()) {
            if (count > 0) {
                double probability = (double) count / totalSize;
                intrinsicValue -= probability * (Math.log(probability) / Math.log(2));
            }
        }

        return intrinsicValue;
    }

    private static double calculateInformationGainRatio(List<String[]> data, int attributeIndex, int targetIndex) {
        double informationGain = calculateInformationGain(data, attributeIndex, targetIndex);
        double intrinsicValue = calculateIntrinsicValue(data, attributeIndex);

        if (intrinsicValue == 0.0) {
            return 0.0;
        }

        return informationGain / intrinsicValue;
    }

    private static double calculateNormalizedWeightedInformationGain(List<String[]> data, int attributeIndex,
            int targetIndex) {
        double informationGain = calculateInformationGain(data, attributeIndex, targetIndex);

        Set<String> uniqueValues = new HashSet<>();
        for (String[] row : data) {
            uniqueValues.add(row[attributeIndex]);
        }

        int k = uniqueValues.size();
        double penaltyFactor = 1.0 - ((double) (k - 1) / data.size());
        double normalizedIG = informationGain / (Math.log(k + 1) / Math.log(2));

        return normalizedIG * penaltyFactor;
    }

    public static double calculateGain(List<String[]> data, int attributeIndex, int targetIndex, GainMetric metric) {
        switch (metric) {
            case IG:
                return calculateInformationGain(data, attributeIndex, targetIndex);
            case IGR:
                return calculateInformationGainRatio(data, attributeIndex, targetIndex);
            case NWIG:
                return calculateNormalizedWeightedInformationGain(data, attributeIndex, targetIndex);
            default:
                throw new IllegalArgumentException("Unknown gain metric: " + metric);
        }
    }

    public static int findBestAttribute(List<String[]> data, int[] featureIndices, int targetIndex, GainMetric metric) {
        double bestGain = -1.0;
        int bestAttribute = -1;

        for (int attributeIndex : featureIndices) {
            double gain = calculateGain(data, attributeIndex, targetIndex, metric);

            if (gain > bestGain) {
                bestGain = gain;
                bestAttribute = attributeIndex;
            }
        }

        return bestAttribute;
    }

    private static void imputeMissingValues(List<String[]> data) {
        if (data.isEmpty())
            return;

        int numColumns = data.get(0).length;
        String[] modes = new String[numColumns];

        System.out.println("Hello");

        for (int col = 0; col < numColumns; col++) {

            Map<String, Integer> freq = new HashMap<>();

            for (String[] row : data) {
                String val = row[col];
                if (!val.equals("?")) {
                    freq.put(val, freq.getOrDefault(val, 0) + 1);
                }
            }

            String mode = null;
            int maxCount = -1;

            for (Map.Entry<String, Integer> entry : freq.entrySet()) {
                if (entry.getValue() > maxCount) {
                    maxCount = entry.getValue();
                    mode = entry.getKey();
                }
            }

            if (mode != null) {
                modes[col] = mode;
            }
        }

        System.out.println("Hello1");

        // Replace '?' with mode
        for (String[] row : data) {
            for (int col = 0; col < numColumns; col++) {
                if (row[col].equals("?")) {
                    row[col] = modes[col];
                }
            }
        }
    }

    static class TreeNode {
        int splitAttribute;
        Map<String, TreeNode> children;
        String label;
        String majorityClass;

        TreeNode(int splitAttribute, String majorityClass) {
            this.splitAttribute = splitAttribute;
            this.children = new HashMap<>();
            this.majorityClass = majorityClass;
        }

        TreeNode(String label) {
            this.splitAttribute = -1;
            this.label = label;
            this.majorityClass = label;
        }

        boolean isLeaf() {
            return splitAttribute == -1;
        }
    }

    
    public static TreeNode buildDecisionTree(List<String[]> data, int[] featureIndices, int targetIndex,
            GainMetric metric, int maxDepth) {

        String majorityClass = majorityClass(data, targetIndex);

        // If all examples have the same class, return a leaf
        if (allSameClass(data, targetIndex)) {
            return new TreeNode(data.get(0)[targetIndex]);
        }

        if (featureIndices.length == 0 || (maxDepth != 0 && maxDepth <= 1)) {
            return new TreeNode(majorityClass);
        }

        int bestAttr = findBestAttribute(data, featureIndices, targetIndex, metric);
        if (bestAttr == -1) {
            return new TreeNode(majorityClass);
        }

        if (allSameAttributeValues(data, featureIndices)) {
            return new TreeNode(majorityClass);
        }

        TreeNode node = new TreeNode(bestAttr, majorityClass);

        Map<String, List<String[]>> partitions = new HashMap<>();

        for (String[] row : data) {
            String value = row[bestAttr];
            if (!partitions.containsKey(value)) {
                partitions.put(value, new ArrayList<>());
            }
            partitions.get(value).add(row);
        }

        int[] newFeatures = new int[featureIndices.length - 1];

        int idx = 0;
        
        for (int feature : featureIndices) {
            if (feature != bestAttr) {
                newFeatures[idx++] = feature;
            }
        }

        int newMaxDepth;
        if (maxDepth == 0) {
            newMaxDepth = 0;
        } else {
            newMaxDepth = maxDepth - 1;
        }

        for (Map.Entry<String, List<String[]>> entry : partitions.entrySet()) {
            if (entry.getValue().isEmpty()) {
                node.children.put(entry.getKey(), new TreeNode(majorityClass));
            } else {
                node.children.put(entry.getKey(),
                        buildDecisionTree(entry.getValue(), newFeatures, targetIndex, metric, newMaxDepth));
            }
        }

        return node;
    }

    private static boolean allSameAttributeValues(List<String[]> data, int[] featureIndices) {
        if (data.isEmpty() || featureIndices.length == 0)
            return true;

        String[] firstRow = data.get(0);
        for (String[] row : data) {
            for (int attrIndex : featureIndices) {
                if (!row[attrIndex].equals(firstRow[attrIndex])) {
                    return false;
                }
            }
        }
        return true;
    }

    private static String majorityClass(List<String[]> data, int targetIndex) {

        Map<String, Integer> counts = new HashMap<>();

        for (String[] row : data) {
            String label = row[targetIndex];
            counts.put(label, counts.getOrDefault(label, 0) + 1);
        }

        String majorityLabel = null;
        int maxCount = -1;

        for (Map.Entry<String, Integer> entry : counts.entrySet()) {
            if (entry.getValue() > maxCount) {
                maxCount = entry.getValue();
                majorityLabel = entry.getKey();
            }
        }
        return majorityLabel;
    }

    public static String predict(TreeNode node, String[] instance) {
        while (!node.isLeaf()) {
            String value = instance[node.splitAttribute];
            TreeNode child = node.children.get(value);
            if (child == null) {
                return node.majorityClass;
            }
            node = child;
        }
        return node.label;
    }

    public static double evaluateModel(TreeNode root, List<String[]> testData, int[] featureIndices,
            int targetIndex) {
        int correct = 0;
        for (String[] row : testData) {
            String pred = predict(root, row);
            if (pred != null && pred.equals(row[targetIndex])) {
                correct++;
            }
        }
        return (double) correct / testData.size();
    }

    private static boolean allSameClass(List<String[]> data, int targetIndex) {
        if (data.isEmpty())
            return true;

        String firstLabel = data.get(0)[targetIndex];
        for (String[] row : data) {
            if (!row[targetIndex].equals(firstLabel)) {
                return false;
            }
        }
        return true;
    }

    public static int countNodes(TreeNode node) {
        if (node.isLeaf())
            return 1;

        int count = 1;
        for (TreeNode child : node.children.values()) {
            count += countNodes(child);
        }
        return count;
    }

    public static int calculateActualDepth(TreeNode node) {
        if (node == null)
            return 0;
        if (node.isLeaf())
            return 1;
        int maxChildDepth = 0;
        for (TreeNode child : node.children.values()) {
            int childDepth = calculateActualDepth(child);
            if (childDepth > maxChildDepth) {
                maxChildDepth = childDepth;
            }
        }
        return 1 + maxChildDepth;
    }
}