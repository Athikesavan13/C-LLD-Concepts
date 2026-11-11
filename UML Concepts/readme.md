

Both Composition and Aggregation describe a **"has-a"** relationship between two classes — but they differ in **ownership** and **lifetime**.

### Composition — "Part Of" (Strong Ownership)

> B creates A. A cannot exist without B. When B dies, A dies too.

- The parent class (`B`) is responsible for **creating and destroying** the child (`A`).
- `A` is born inside `B`'s constructor and deleted in `B`'s destructor.
- If you delete `B`, `A` is gone automatically.

```cpp
class B_Composition {
    A* a;
public:
    B_Composition(string name) {
        a = new A(name);  // B creates A
    }
    ~B_Composition() {
        delete a;         // B destroys A
    }
};
```

### Aggregation — "Uses A" (Weak Ownership)

> C borrows A. A exists independently. When C dies, A is still alive.

- The parent class (`C`) receives a **pointer to an already-existing** `A`.
- `C` does not delete `A` in its destructor — it just stops pointing to it.
- `A`'s lifetime is managed entirely from outside `C`.

```cpp
class C_Aggregation {
    A* a;
public:
    C_Aggregation(A* aPtr) {
        a = aPtr;   // C borrows A — does NOT own it
    }
    ~C_Aggregation() {
        a = nullptr; // just stop pointing, never delete
    }
};
```

The code uses standard C++ exceptions to guard against bad input.
```

| Situation                        | Exception Thrown          |
|----------------------------------|---------------------------|
| Empty name passed to `A`         | `std::invalid_argument`   |
| `nullptr` passed to `C`          | `std::invalid_argument`   |
| Calling methods on a null `A*`   | `std::runtime_error`      |
```

All exceptions are caught with `try / catch` blocks in `main`, so the program continues cleanly after each error.


## How to Compile and Run

```bash
g++ -std=c++17 -Wall main.cpp -o demo
./demo
```
Result

```
A created Using Comstructor
 Dummy Method of B_ Compostion
 Dummy Method of B_ Compostion
Dummy Method in A
B Compostiion Destructed
 A Deleted Using Destructor
A created Using Comstructor

C Aggregation Constructor called
C aggreation Using ABeta
C aggreation Using ABeta
Dummy Method in A
Destructor for C agrregation called
 No need to delete A pointer just make it null becuse it was never created it just referenced
Dummy Method in A
 A Deleted Using Destructor
 ```
