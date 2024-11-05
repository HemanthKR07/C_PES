import React from 'react';

const Task = ({ task, deleteTask, toggleComplete, setCurrentTask }) => {
  const taskStyle = {
    textDecoration: task.completed ? 'line-through' : 'none',
  };

  return (
    <div className="flex items-center justify-between p-2 border-b">
      <span style={taskStyle} className="flex-1">
        {task.description} - {task.category}
      </span>
      <button
        onClick={() => toggleComplete(task.id)}
        className={`p-2 rounded ${task.completed ? 'bg-green-500' : 'bg-gray-500'} text-white`}
      >
        {task.completed ? 'Incomplete' : 'Complete'}
      </button>
      <button
        onClick={() => setCurrentTask(task)}
        className="bg-yellow-500 text-white p-2 rounded ml-2"
      >
        Edit
      </button>
      <button
        onClick={() => deleteTask(task.id)}
        className="bg-red-500 text-white p-2 rounded ml-2"
      >
        Delete
      </button>
    </div>
  );
};

export default Task;