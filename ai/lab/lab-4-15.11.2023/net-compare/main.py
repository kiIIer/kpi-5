import numpy as np
import tensorflow as tf
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt


def generate_data(num_samples=500):
    x_values = np.random.uniform(0, 5, num_samples)
    y_values = np.random.uniform(0, 5, num_samples)
    z_values = np.square(x_values) + y_values
    input_data = np.column_stack((x_values, y_values))
    output_data = z_values.reshape(-1, 1)
    return input_data, output_data


def create_feedforward_model_a():
    model = tf.keras.Sequential([
        tf.keras.layers.Dense(10, activation='relu', input_shape=(2,)),
        tf.keras.layers.Dense(1)
    ])
    return model


def create_feedforward_model_b():
    model = tf.keras.Sequential([
        tf.keras.layers.Dense(20, activation='relu', input_shape=(2,)),
        tf.keras.layers.Dense(1)
    ])
    return model


def create_cascade_forward_model_a():
    model = tf.keras.Sequential([
        tf.keras.layers.Dense(20, activation='relu', input_shape=(2,)),
        tf.keras.layers.Dense(1)
    ])
    return model


def create_cascade_forward_model_b():
    model = tf.keras.Sequential([
        tf.keras.layers.Dense(10, activation='relu', input_shape=(2,)),
        tf.keras.layers.Dense(10, activation='relu'),
        tf.keras.layers.Dense(1)
    ])
    return model


def create_elman_model_a():
    model = tf.keras.Sequential([
        tf.keras.layers.SimpleRNN(15, activation='relu', input_shape=(1, 2)),
        tf.keras.layers.Dense(1)
    ])
    return model


def create_elman_model_b():
    model = tf.keras.Sequential([
        tf.keras.layers.SimpleRNN(5, activation='relu', return_sequences=True, input_shape=(1, 2)),
        tf.keras.layers.SimpleRNN(5, activation='relu', return_sequences=True),
        tf.keras.layers.SimpleRNN(5, activation='relu'),
        tf.keras.layers.Dense(1)
    ])
    return model


def compile_and_train(model, X_train, y_train, X_val, y_val, epochs=100):
    model.compile(optimizer='adam', loss='mean_squared_error')
    history = model.fit(X_train, y_train, epochs=epochs, validation_data=(X_val, y_val), verbose=0)
    return history


input_data, output_data = generate_data()

input_data_rnn = input_data.reshape(input_data.shape[0], 1, input_data.shape[1])

X_train, X_test, y_train, y_test = train_test_split(input_data, output_data, test_size=0.2, random_state=42)
X_train_rnn, X_test_rnn = X_train.reshape(X_train.shape[0], 1, 2), X_test.reshape(X_test.shape[0], 1, 2)

models = {
    'Feedforward Model A (10 Neurons)': create_feedforward_model_a(),
    'Feedforward Model B (20 Neurons)': create_feedforward_model_b(),
    'Cascade Model A (20 Neurons)': create_cascade_forward_model_a(),
    'Cascade Model B (2x10 Neurons)': create_cascade_forward_model_b(),
    'Elman Model A (15 Neurons)': create_elman_model_a(),
    'Elman Model B (3x5 Neurons)': create_elman_model_b()
}

histories = {}
for name, model in models.items():
    print(f'Training {name}...')
    if 'Elman' in name:
        history = compile_and_train(model, X_train_rnn, y_train, X_test_rnn, y_test, epochs=100)
    else:
        history = compile_and_train(model, X_train, y_train, X_test, y_test, epochs=100)
    histories[name] = history

    final_training_loss = history.history['loss'][-1]
    final_validation_loss = history.history['val_loss'][-1]
    print(f"Model: {name}")
    print(f" - Final Training Loss: {final_training_loss:.4f}")
    print(f" - Final Validation Loss: {final_validation_loss:.4f}\n")

plt.figure(figsize=(15, 10))
for name, history in histories.items():
    plt.plot(history.history['loss'], label=f'{name} - Training Loss')
    plt.plot(history.history['val_loss'], label=f'{name} - Validation Loss')

plt.title('Training and Validation Loss Over Epochs')
plt.xlabel('Epochs')
plt.ylabel('Mean Squared Error')
plt.legend()
plt.show()
