CREATE TABLE students (
    id INTEGER,
    student_name TEXT,
    -- house TEXT,
    -- head TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE houses (
    house_id INTEGER,
    house_name TEXT,
    head TEXT,
    PRIMARY KEY(house_id)
);

CREATE TABLE assignments (
    assignments_id INTEGER,
    student_id INTEGER,
    house_id INTEGER,
    PRIMARY KEY(assignments_id),
    FOREIGN KEY(student_id) REFERENCES students(id),
    FOREIGN KEY(house_id) REFERENCES houses(house_id)
);

-- Sławek