## Building
Requirements:

- Meson 0.49 or newer
- Ninja 1.8.2 or newer

```bash
meson build
```

To build the project from then on:

```bash
ninja -C build
```

To run the tests:

```bash
ninja -C build test
```

To run the tests with full "google test" reporting:

```bash
./build/run_tests
```

All build files will be put in the **build** directory, which is included in .gitignore.
