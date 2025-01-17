# Project Setup Document
## Introduction
- To help contributors or users prepare their environment to run or develop the project.

## Prerequisites
- Software Requirements:
    - Operating system compatibility (e.g., "Tested on Windows 10, macOS Ventura, and Ubuntu 22.04").
    - Required tools or software (e.g., Python, Node.js, Java, Docker).
- Accounts or Keys (if needed):
    - Mention if contributors need to create accounts, obtain API keys, or set up specific permissions.

## Installation Steps
- Clone the Repository:
    ```bash
    Copy code
    git clone https://github.com/username/repository.git
    cd repository
    ```
- Install Dependencies:
    - For example:
        - Python: pip install -r requirements.txt
        - Node.js: npm install
        - Java: Specify Maven or Gradle commands.
    - Environment Configuration:
        - Setting up environment variables or .env files.
        - Example:
            ```plaintext
            Copy code
            API_KEY=your_api_key_here
            DATABASE_URL=your_database_url_here
            ```
        - Instructions for creating or editing the configuration file.

## Setting Up Development Tools

| Software    | Version | Link                                                   |
|:------------|--------:|--------------------------------------------------------|
| Arduino IDE |  1.8.18 | https://www.arduino.cc/en/software/OldSoftwareReleases |
- Recommended IDEs or editors (e.g., VSCode, IntelliJ).
- List required extensions or plugins (e.g., Prettier, ESLint).
- Code formatting or linting instructions.



## Verifying the Setup
- How to test that the setup is correct.
    - Example: Run a test command:
        ```bash
        Copy code
        npm run test
        ```
- Check application functionality:
    - Example: "Run the application and verify that http://localhost:3000 is accessible."

## Troubleshooting
- Common issues users might encounter and how to resolve them.
- Links to additional resources or FAQs.

## Optional: Advanced Setup
- Instructions for setting up Docker or virtual environments for isolation.
- Multi-environment configuration (e.g., development, testing, production).

## Contributing (if applicable)
- Direct contributors to additional resources like a CONTRIBUTING.md file.
- Mention coding standards or Git workflows.

## References
- Links to related documentation (e.g., third-party libraries, APIs, or frameworks).
- Links to project-specific resources, like design documents or diagrams.

- https://www.espboards.dev/blog/setting-up-arduino-ide-esp32/
- https://medium.com/home-wireless/use-visual-studio-code-for-arduino-2d0cf4c1760b
- https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/
- https://github.com/me-no-dev/arduino-esp32fs-plugin/releases/
- https://randomnerdtutorials.com/vs-code-platformio-ide-esp32-esp8266-arduino/
- https://stackoverflow.com/questions/62662662/why-is-vs-code-throwing-this-error-arduino
- https://maker.pro/arduino/tutorial/how-to-use-visual-studio-code-for-arduino