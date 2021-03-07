# Unix-like OS Commands

## Representation of Paths

| PATH                | COMMAND |
|---------------------|---------|
| Root Directory      | `/`     |
| Directory Separator | `/`     |
| Current Directory   | `.`     |
| Parent Directory    | `..`    |
| Home Directory      | `~`     |

## Basic Shell Commands

- `pwd`: Show the current full path.
- `ls`: **List** files in the current direction.
- `ls -a`: Show all files, including hiding files which name start as a `.`dot.
- `cd {dir_name}`: **Change directory** to the target whose name is "dir_name".
- `mkdir {dir_name}`: **Make a new directory** under current path called "dir_name".
- `rm {file_name}`: **Remove** or delete the **single file** called "file_name".
- `rm -r {dir_name}`: **Remove** the **directory** and all including files called "dir_name" recursively.
- `mv {old_path} {new_path}`: Move a file from "old_path" to "new_path", or rename it. Actually, they are same.
