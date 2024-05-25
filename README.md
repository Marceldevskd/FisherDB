# FisherDB

A hobby SQL based database system made in c++  

Example file structure:  

```md
- FisherDB
  - src
    - query_runners
      - create
        - CreateQueryRunner.cpp
        - CreateQueryRunner.h
      - read
        - ReadQueryRunner.cpp
        - ReadQueryRunner.h
      - update
        - UpdateQueryRunner.cpp
        - UpdateQueryRunner.h
      - delete
        - DeleteQueryRunner.cpp
        - DeleteQueryRunner.h
    - tools
      - StringUtils.cpp
      - StringUtils.h
      - DataValidation.cpp
      - DataValidation.h
      - DBConnection.cpp
      - DBConnection.h
      - Logging.cpp
      - Logging.h
    - config
      - DBConfig.h
      - Settings.h
    - main
      - main.cpp
  - tests
    - test_create.cpp
    - test_read.cpp
    - test_update.cpp
    - test_delete.cpp
    - test_string_utils.cpp
  - docs
    - README.md
    - API.md
    - setup_guide.md
```
