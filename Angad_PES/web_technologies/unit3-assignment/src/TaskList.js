import React from 'react';
import Task from './Task';

const TaskList = ({ tasks, deleteTask, toggleComplete, setCurrentTask }) => {
  return (
    <div>
      {tasks.map(task => (
        <Task
          key={task.id}
          task={task}
          deleteTask={deleteTask}
          toggleComplete={toggleComplete}
          setCurrentTask={setCurrentTask}
        />
      ))}
    </div>
  );
};

export default TaskList;