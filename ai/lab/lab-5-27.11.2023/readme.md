# Лабораторна робота №5

## Тема

Моделювання нейронної мережі Хебба

## Мета

Промоделювати та дослідити нейронну мережу Хебба.

## Виконання

### 1. Розробка Структури Мережі Хебба

Мережа Хебба - це простий вид нейронної мережі, заснованої на правилі Хебба, яке стверджує, що зв'язки між нейронами посилюються, коли вони активуються одночасно. Для розпізнавання літер можна використовувати двошарову мережу: вхідний шар, де кожен нейрон відповідає одній точці зображення літери, і вихідний шар, де кожен нейрон відповідає одній літері.

### 2. Розробка Алгоритму та Програми

Алгоритм роботи мережі Хебба має включати наступні етапи:

- **Ініціалізація ваг:** Початкові ваги зв'язків між нейронами можуть бути встановлені нульовими значеннями.
- **Тренування:** Під час тренування мережі ваги зв'язків коригуються згідно з правилом Хебба.
- **Розпізнавання:** Під час розпізнавання активуються вхідні нейрони, що відповідають зображенню літери, і через ваги зв'язків передається сигнал до виходу. Найбільш активований вихідний нейрон вказує на розпізнану літеру.

### 3. Навчання Нейронної Мережі

Я обрав чотири літери мого імені і підготував навчальні дані для кожної літери. Для кожної літери створив зображення у двійковому форматі (де 1 означає активований піксель, а 0 - неактивований). Використаємо ці данні для навчання моделі.

### Код

Код знаходиться за посиланням [[hebb]](./hebb/)

Для зручності я створив клас нейрона, де він сам себе ініціалізує, та методи для розпізнавання та навчання. Після певного періоду навчання, можна вважати що система готова.

### Тестування

Після навчання, ось результати роботи моделі:

```python
{'M': [1, 0, 0, 0], 'I': [0, 1, 0, 0], 'K': [0, 0, 1, 0], 'E': [0, 0, 0, 1], 'A': [1, 0, 0, 0], 'B': [0, 0, 0, 0]}
```

Як бачимо, модель з легкістю змогла розпізнати літери мого імені, бо кожен нейрон активувався тільки якщо це справді була та літера. Я вирішив ще й інші літери туди закинути, та вийшло, що А дуже схожа на М, тому той нейрон і активувався(бо не був навчений цього не робити), але всі змогли зрозуміти, що В це не їх літера.

Переглянемо ваги нейрона М.

![Рисунок 1 - Ваги нейрона М](image.png)

## Висновок

На цій лабораторній роботі я познайомився з нейронною мережею Хебба, створив свої власні нейрони та натренував їх за наданим алгоритмом для розпізнавання літер мого імені.