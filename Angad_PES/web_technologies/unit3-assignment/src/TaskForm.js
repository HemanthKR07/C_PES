import React, { useState, useEffect } from 'react';

const TaskForm = ({ addTask, editTask, currentTask, setCurrentTask }) => {
  const [task, setTask] = useState({ description: '', category: '', completed: false });

  useEffect(() => {
    if (currentTask) {
      setTask(currentTask);
    }
  }, [currentTask]);

  const handleChange = (e) => {
    const { name, value } = e.target;
    setTask({ ...task, [name]: value });
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    if (currentTask) {
      editTask(task);
    } else {
      addTask(task);
    }
    setTask({ description: '', category: '', completed: false });
    setCurrentTask(null);
  };

  return (
    <form onSubmit={handleSubmit} className="mb-4">
      <input
        type="text"
        name="description"
        value={task.description}
        onChange={handleChange}
        placeholder="Task Description"
        required
        className="border p-2 mb-2 w-full"
      />
      <input
        type="text"
        name="category"
        value={task.category}
        onChange={handleChange}
        placeholder="Category"
        required
        className="border p-2 mb-2 w-full"
      />
      <button type="submit" className="bg-blue-500 text-white p-2 rounded">
        {currentTask ? 'Edit Task' : 'Add Task'}
      </button>
    </form>
  );
};

export default TaskForm;