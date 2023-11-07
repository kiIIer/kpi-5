int bpm = 120;
int speakerPin = 6;

typedef enum
{
    C,
    CSharp,
    D,
    DSharp,
    E,
    F,
    FSharp,
    G,
    GSharp,
    A,
    ASharp,
    B
} Note;

typedef struct
{
    Note note;
    int octave;
    int type;
    bool dotted;
} MusicalNote;

double noteToFrequency(MusicalNote mn);
unsigned int calculateNoteDuration(MusicalNote mn);
void playNote(int speakerPin, MusicalNote mn);
MusicalNote createNote(Note n, int octave, int type, bool dotted);

MusicalNote music[131];

void setupmusic()
{
    int i = 0;
    // 1
    music[i++] = createNote(G, 5, 8, false);
    music[i++] = createNote(FSharp, 5, 8, false);
    music[i++] = createNote(E, 5, 8, false);
    music[i++] = createNote(D, 5, 8, false);

    // 2
    music[i++] = createNote(E, 5, 4, true);
    music[i++] = createNote(D, 5, 8, false);
    music[i++] = createNote(E, 5, 4, false);
    music[i++] = createNote(G, 5, 4, false);

    // 3
    music[i++] = createNote(FSharp, 5, 2, false);
    music[i++] = createNote(G, 5, 8, false);
    music[i++] = createNote(FSharp, 5, 8, false);
    music[i++] = createNote(E, 5, 8, false);
    music[i++] = createNote(D, 5, 8, false);

    // 4
    music[i++] = createNote(E, 5, 4, true);
    music[i++] = createNote(D, 5, 8, false);
    music[i++] = createNote(B, 4, 4, false);
    music[i++] = createNote(E, 5, 4, false);

    // 5
    music[i++] = createNote(FSharp, 5, 2, false);
    music[i++] = createNote(G, 5, 8, false);
    music[i++] = createNote(FSharp, 5, 8, false);
    music[i++] = createNote(E, 5, 8, false);
    music[i++] = createNote(D, 5, 8, false);

    // 6
    music[i++] = createNote(E, 5, 4, true);
    music[i++] = createNote(D, 5, 8, false);
    music[i++] = createNote(E, 5, 4, false);
    music[i++] = createNote(G, 5, 4, false);

    // 7
    music[i++] = createNote(FSharp, 5, 2, false);
    music[i++] = createNote(G, 5, 8, false);
    music[i++] = createNote(FSharp, 5, 8, false);
    music[i++] = createNote(E, 5, 8, false);
    music[i++] = createNote(D, 5, 8, false);

    // 8
    music[i++] = createNote(E, 5, 4, true);
    music[i++] = createNote(D, 5, 8, false);
    music[i++] = createNote(B, 4, 4, false);
    music[i++] = createNote(E, 5, 4, false);

    // 9
    music[i++] = createNote(FSharp, 5, 2, false);
    music[i++] = createNote(G, 5, 8, false);
    music[i++] = createNote(FSharp, 5, 8, false);
    music[i++] = createNote(E, 5, 8, false);
    music[i++] = createNote(D, 5, 8, false);

    // 2
    music[i++] = createNote(E, 5, 4, true);
    music[i++] = createNote(D, 5, 8, false);
    music[i++] = createNote(E, 5, 4, false);
    music[i++] = createNote(G, 5, 4, false);

    // 3
    music[i++] = createNote(FSharp, 5, 2, false);
    music[i++] = createNote(G, 5, 8, false);
    music[i++] = createNote(FSharp, 5, 8, false);
    music[i++] = createNote(E, 5, 8, false);
    music[i++] = createNote(D, 5, 8, false);

    // 4
    music[i++] = createNote(E, 5, 4, true);
    music[i++] = createNote(D, 5, 8, false);
    music[i++] = createNote(B, 4, 4, false);
    music[i++] = createNote(E, 5, 4, false);

    // 5
    music[i++] = createNote(FSharp, 5, 2, false);
    music[i++] = createNote(G, 5, 8, false);
    music[i++] = createNote(FSharp, 5, 8, false);
    music[i++] = createNote(E, 5, 8, false);
    music[i++] = createNote(D, 5, 8, false);

    // 6
    music[i++] = createNote(E, 5, 4, true);
    music[i++] = createNote(D, 5, 8, false);
    music[i++] = createNote(E, 5, 4, false);
    music[i++] = createNote(G, 5, 4, false);

    // 7
    music[i++] = createNote(FSharp, 5, 2, false);
    music[i++] = createNote(G, 5, 8, false);
    music[i++] = createNote(FSharp, 5, 8, false);
    music[i++] = createNote(E, 5, 8, false);
    music[i++] = createNote(D, 5, 8, false);

    // 8
    music[i++] = createNote(E, 5, 4, true);
    music[i++] = createNote(D, 5, 8, false);
    music[i++] = createNote(B, 4, 4, false);
    music[i++] = createNote(E, 5, 4, false);

    // 10
    music[i++] = createNote(D, 5, 1, false);
    music[i++] = createNote(D, 5, 1, false);

    // 11
    music[i++] = createNote(D, 5, 1, false);

    // 12
    music[i++] = createNote(D, 5, 4, true);
    music[i++] = createNote(FSharp, 4, 8, false);
    music[i++] = createNote(G, 4, 4, false);
    music[i++] = createNote(A, 4, 4, false);

    // 13
    music[i++] = createNote(B, 4, 2, true);
    music[i++] = createNote(A, 4, 8, false);
    music[i++] = createNote(B, 4, 8, false);

    // 14
    music[i++] = createNote(C, 5, 4, false);
    music[i++] = createNote(B, 4, 4, false);
    music[i++] = createNote(A, 4, 4, true);
    music[i++] = createNote(G, 4, 8, false);

    // 15
    music[i++] = createNote(B, 4, 1, false);

    // 17
    music[i++] = createNote(FSharp, 4, 8, false);
    music[i++] = createNote(G, 4, 4, false);
    music[i++] = createNote(A, 4, 4, false);

    // 18
    music[i++] = createNote(B, 4, 2, true);
    music[i++] = createNote(B, 4, 8, false);
    music[i++] = createNote(G, 4, 8, false);

    // 19
    music[i++] = createNote(FSharp, 4, 2, false);
    music[i++] = createNote(B, 4, 8, false);
    music[i++] = createNote(G, 4, 8, false);

    // 20
    music[i++] = createNote(FSharp, 4, 2, true);
    music[i++] = createNote(G, 4, 4, false);
    music[i++] = createNote(A, 4, 4, false);

    // 21
    music[i++] = createNote(B, 4, 8, false);
    music[i++] = createNote(A, 4, 8, false);
    music[i++] = createNote(G, 4, 8, false);
    music[i++] = createNote(FSharp, 4, 8, false);

    // 22
    music[i++] = createNote(B, 4, 1, false);

    music[i++] = createNote(B, 4, 4, true);
    music[i++] = createNote(FSharp, 4, 8, false);
    music[i++] = createNote(G, 4, 4, false);
    music[i++] = createNote(A, 4, 4, false);

    // 13
    music[i++] = createNote(B, 4, 2, true);
    music[i++] = createNote(A, 4, 8, false);
    music[i++] = createNote(B, 4, 8, false);

    // 14
    music[i++] = createNote(C, 5, 4, false);
    music[i++] = createNote(B, 4, 4, false);
    music[i++] = createNote(A, 4, 4, true);
    music[i++] = createNote(G, 4, 8, false);

    // 15
    music[i++] = createNote(B, 4, 1, false);

    // 17
    music[i++] = createNote(FSharp, 4, 8, false);
    music[i++] = createNote(G, 4, 4, false);
    music[i++] = createNote(A, 4, 4, false);

    // 18
    music[i++] = createNote(B, 4, 2, true);
    music[i++] = createNote(B, 4, 8, false);
    music[i++] = createNote(G, 4, 8, false);

    // 19
    music[i++] = createNote(FSharp, 4, 2, false);
    music[i++] = createNote(B, 4, 8, false);
    music[i++] = createNote(G, 4, 8, false);

    // 20
    music[i++] = createNote(FSharp, 4, 2, true);
    music[i++] = createNote(G, 4, 4, false);
    music[i++] = createNote(A, 4, 4, false);

    // 21
    music[i++] = createNote(B, 4, 8, false);
    music[i++] = createNote(A, 4, 8, false);
    music[i++] = createNote(G, 4, 8, false);
    music[i++] = createNote(FSharp, 4, 8, false);
    Serial.begin(9600);
    Serial.println(i);
}

void setup()
{
    setupmusic();
}

void loop()
{
    for (int i = 0; i < 131; ++i)
    {
        playNote(speakerPin, music[i]);
    }
}

double noteToFrequency(MusicalNote mn)
{
    double baseFrequencies[] = {
        261.63, // C
        277.18, // C#
        293.66, // D
        311.13, // D#
        329.63, // E
        349.23, // F
        369.99, // F#
        392.00, // G
        415.30, // G#
        440.00, // A
        466.16, // A#
        493.88  // B
    };

    double frequency = baseFrequencies[mn.note] * pow(2.0, mn.octave - 4);
    return frequency;
}

unsigned int calculateNoteDuration(MusicalNote mn)
{
    unsigned int wholeNoteDuration = (60000 * 4) / bpm;
    unsigned int duration = wholeNoteDuration / mn.type;
    if (mn.dotted)
    {
        duration += duration / 2;
    }
    return duration;
}

void playNote(int speakerPin, MusicalNote mn)
{
    double frequency = noteToFrequency(mn);
    unsigned int duration = calculateNoteDuration(mn);

    tone(speakerPin, (unsigned int)frequency, duration);
    delay(duration + 10);
}

MusicalNote createNote(Note n, int octave, int type, bool dotted)
{
    MusicalNote mn;
    mn.note = n;
    mn.octave = octave;
    mn.type = type;
    mn.dotted = dotted;
    return mn;
}