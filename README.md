
# Log File Analyzer

## About the Project

**Log File Analyzer** is a scalable and robust log analysis and management system, designed for use in large-scale companies and high-complexity projects. Our goal is to provide a flexible and powerful tool for quickly searching and filtering log data, supporting a structured, secure, and adaptable solution for working with log files.

### Key Features

- **Date and Time Filtering**: Convenient and accurate log search by specified time intervals.
- **Type and Content Filtering**: Support for filtering logs by type (e.g., `ERROR`, `INFO`) and by keywords in messages.
- **Full Log Output**: Ability to display all log entries without filtering.
- **Multithreaded Processing Support**: Safe data handling in multithreaded environments using mutexes.

## Requirements

To use **Log File Analyzer**, you need:

- Project build system: `CMake` version 3.10 or higher
- Compiler supporting the **C11** standard
- **POSIX-compliant system** (Linux, macOS) or POSIX API support for Windows (e.g., **MinGW**)

## Installation

1. **Clone the repository**:
   ```bash
   git https://github.com/Awl-S/LogFile-Analyzer.git
   cd log-file-analyzer
   ```

2. **Build the project using CMake**:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run**:
   After building, you can run the application:
   ```bash
   ./Log_File_Analyzer <path to log file> [options]
   ```

## Usage

**Log File Analyzer** accepts the log file path and filtering parameters as input. Command syntax:
```bash
./Log_File_Analyzer <path to log file> [options]
```

### Command-line Options

- `--date [year] [month] [day]`: Filter logs by date
- `--time [start_time] [end_time]`: Filter logs by time range (format HH:MM)
- `--type [log_type]`: Filter logs by message type (e.g., `ERROR`, `INFO`)
- `--message [substring]`: Search for log entries containing the specified message substring
- `--full`: Display all log entries without filtering
- `--help`: Show help information

### Usage Examples

- Search for logs on a specific day:
  ```bash
  ./Log_File_Analyzer ../data/log.txt --date 2022 10 30
  ```

- Filter logs by time range:
  ```bash
  ./Log_File_Analyzer ../data/log.txt --time 08:00 12:00
  ```

- Display all logs without filtering:
  ```bash
  ./Log_File_Analyzer ../data/log.txt --full
  ```

## Project Structure

- **src/** — Project source code
    - **main.c** — Application entry point
    - **log_entry.c** — Module for log entry operations (adding, loading, printing)
    - **search.c** — Module for log filtering by various criteria
    - **utils.c** — Utility functions for working with time intervals
- **include/** — Header files for modules
- **data/** — Sample data for testing

### Key Development Considerations

- **Thread Safety**: The project uses the `logMutex` mutex to synchronize access to log data in multithreaded conditions.
- **Configuration**: All parameters, such as log file path and filtering options, are specified via the command line. Ensure the `parseArguments` function in `main.c` correctly handles all new parameters.

### Example Tests

- Test 1: Date Filtering
  ```bash
  ./Log_File_Analyzer ../data/log.txt --date 2023 01 15
  ```
  Expected result: Only logs created on January 15, 2023, are displayed.

- Test 2: Time Range Filtering
  ```bash
  ./Log_File_Analyzer ../data/log.txt --time 09:00 11:00
  ```
  Expected result: Logs created between 9:00 and 11:00 are displayed.

## Contributing

We welcome contributions to the project. Please follow our style and testing guidelines before creating a Pull Request. Refer to `CONTRIBUTING.md` for more detailed information.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

## Support

If you have questions or suggestions to improve **Log File Analyzer**, please contact us at batnikov@internet.ru

---
