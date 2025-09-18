import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns

# Set the style for attractive plots
plt.style.use('seaborn-v0_8')
sns.set_palette("husl")

# Read the CSV file
df = pd.read_csv('decision_tree_experiments_Iris.csv')

# Define colors and markers for each criteria - more distinct colors
colors = ['#FF6B6B', '#8B4513', '#2E8B57']  # Red, Brown, Sea Green
markers = ['o', 'D', '^']  # Circle, Diamond, Triangle
criteria_list = ['IG', 'IGR', 'NWIG']

# --- Plot 1: Average Accuracy vs Max Tree Depth ---
plt.figure(figsize=(12, 8))

all_depths = np.arange(df['MaxDepth'].min(), df['MaxDepth'].max() + 1)

for i, criteria in enumerate(criteria_list):
    criteria_data = df[df['Criteria'] == criteria]
    # Group by MaxDepth and calculate mean and std
    grouped = criteria_data.groupby('MaxDepth')['Accuracy'].agg(['mean', 'std', 'count']).reindex(all_depths)
    plt.errorbar(
        all_depths, grouped['mean'], yerr=grouped['std'], fmt=markers[i]+'-',
        color=colors[i], label=f'{criteria}', linewidth=2, markersize=8, capsize=5, alpha=0.9
    )
    # Scatter actual points
    plt.scatter(criteria_data['MaxDepth'], criteria_data['Accuracy'], color=colors[i], s=60, alpha=0.7, zorder=5)

plt.xlabel('Maximum Tree Depth', fontsize=14, fontweight='bold')
plt.ylabel('Accuracy', fontsize=14, fontweight='bold')
plt.title('Decision Tree Accuracy vs Maximum Depth', fontsize=16, fontweight='bold', pad=20)
plt.legend(fontsize=12, frameon=True, fancybox=True, shadow=True)
plt.grid(True, alpha=0.3)
plt.ylim(df['Accuracy'].min() - 0.05, df['Accuracy'].max() + 0.05)
plt.xlim(df['MaxDepth'].min() - 0.5, df['MaxDepth'].max() + 0.5)

# Add statistics as text
stats_text = f"""
Dataset Statistics:
• Total experiments: {len(df)}
• MaxDepth range: {df['MaxDepth'].min()} - {df['MaxDepth'].max()}
• Accuracy range: {df['Accuracy'].min():.3f} - {df['Accuracy'].max():.3f}
"""
plt.figtext(0.02, 0.02, stats_text, fontsize=11, 
         bbox=dict(boxstyle='round,pad=0.5', facecolor='lightgray', alpha=0.8))

plt.tight_layout()
plt.savefig('accuracy_vs_depth2.png', dpi=300, bbox_inches='tight', 
            facecolor='white', edgecolor='none')
plt.show()

# --- Plot 2: Number of Nodes vs Actual Tree Depth ---
plt.figure(figsize=(12, 8))

all_actual_depths = np.arange(df['ActualDepth'].min(), df['ActualDepth'].max() + 1)

for i, criteria in enumerate(criteria_list):
    criteria_data = df[df['Criteria'] == criteria]
    grouped = criteria_data.groupby('ActualDepth')['NodeCount'].agg(['mean', 'std', 'count']).reindex(all_actual_depths)
    plt.errorbar(
        all_actual_depths, grouped['mean'], yerr=grouped['std'], fmt=markers[i]+'-',
        color=colors[i], label=f'{criteria}', linewidth=2, markersize=8, capsize=5, alpha=0.9
    )
    plt.scatter(criteria_data['ActualDepth'], criteria_data['NodeCount'], color=colors[i], s=60, alpha=0.7, zorder=5)

plt.xlabel('Actual Tree Depth', fontsize=14, fontweight='bold')
plt.ylabel('Number of Nodes', fontsize=14, fontweight='bold')
plt.title('Decision Tree Node Count vs Actual Depth', fontsize=16, fontweight='bold', pad=20)
plt.legend(fontsize=12, frameon=True, fancybox=True, shadow=True)
plt.grid(True, alpha=0.3)
plt.ylim(df['NodeCount'].min() - 2, df['NodeCount'].max() + 2)
plt.xlim(df['ActualDepth'].min() - 0.5, df['ActualDepth'].max() + 0.5)

# Add statistics as text
stats_text = f"""
Dataset Statistics:
• Total experiments: {len(df)}
• ActualDepth range: {df['ActualDepth'].min()} - {df['ActualDepth'].max()}
• Node count range: {df['NodeCount'].min()} - {df['NodeCount'].max()}
"""
plt.figtext(0.02, 0.02, stats_text, fontsize=11, 
         bbox=dict(boxstyle='round,pad=0.5', facecolor='lightgray', alpha=0.8))

plt.tight_layout()
plt.savefig('nodes_vs_depth2.png', dpi=300, bbox_inches='tight', 
            facecolor='white', edgecolor='none')
plt.show()
