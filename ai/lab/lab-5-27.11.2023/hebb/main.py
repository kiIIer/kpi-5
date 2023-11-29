import numpy as np

A = np.array([
    [0, 0, 1, 0, 0],
    [0, 1, 0, 1, 0],
    [1, 1, 1, 1, 1],
    [1, 0, 0, 0, 1],
    [1, 0, 0, 0, 1]
]).flatten()

B = np.array([
    [1, 1, 1, 0, 0],
    [1, 0, 0, 1, 0],
    [1, 1, 1, 0, 0],
    [1, 0, 0, 1, 0],
    [1, 1, 1, 0, 0]
]).flatten()

M = np.array([
    [1, 0, 0, 0, 1],
    [1, 1, 0, 1, 1],
    [1, 0, 1, 0, 1],
    [1, 0, 0, 0, 1],
    [1, 0, 0, 0, 1]
]).flatten()
I = np.array([
    [0, 1, 1, 1, 0],
    [0, 0, 1, 0, 0],
    [0, 0, 1, 0, 0],
    [0, 0, 1, 0, 0],
    [0, 1, 1, 1, 0]
]).flatten()
K = np.array([
    [0, 1, 0, 0, 1],
    [0, 1, 0, 1, 0],
    [0, 1, 1, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 1, 0, 0, 1]
]).flatten()
E = np.array([
    [0, 1, 1, 1, 0],
    [0, 1, 0, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 1, 0, 0, 0],
    [0, 1, 1, 1, 0]
]).flatten()

training_inp = np.array([M.flatten(), I.flatten(), K.flatten(), E.flatten()])
training_out = np.array([[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]])


class Neuron:
    def __init__(self):
        self.weights = np.zeros(25)

    def predict(self, inp):
        activation = np.dot(self.weights, inp)
        return 1 if activation >= 0 else 0

    def learn(self, inp, target):
        if target == 1 and self.predict(inp) == 0:
            self.weights += inp  # Strengthen weights
        elif target == 0 and self.predict(inp) == 1:
            self.weights -= inp  # Weaken weights


neurons = [Neuron(), Neuron(), Neuron(), Neuron()]

for i in range(100):
    for (inp, targets) in zip(training_inp, training_out):
        for (neuron, target) in zip(neurons, targets):
            neuron.learn(inp, target)

results = {}

letters = ['M', 'I', 'K', 'E', 'A', 'B']
for i, letter in enumerate([M, I, K, E, A, B]):
    predictions = [neuron.predict(letter) for neuron in neurons]
    results[letters[i]] = predictions

print(results)
