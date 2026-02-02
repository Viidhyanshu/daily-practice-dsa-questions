"use client";

import React, { useState } from "react";

export default function Navbar() {
  const [menuOpen, setMenuOpen] = useState(false);

  return (
    <nav className="relative bg-gray-800/50 border-b border-white/10">
      <div className="mx-auto max-w-7xl px-2 sm:px-6 lg:px-8">
        <div className="flex h-16 items-center justify-between">

          {/* Mobile Button */}
          <button
            onClick={() => setMenuOpen(!menuOpen)}
            className="sm:hidden p-2 text-gray-400 hover:text-white"
          >
            {!menuOpen ? (
              <svg
                viewBox="0 0 24 24"
                fill="none"
                stroke="currentColor"
                strokeWidth="1.5"
                className="h-6 w-6"
              >
                <path
                  d="M3.75 6.75h16.5M3.75 12h16.5m-16.5 5.25h16.5"
                  strokeLinecap="round"
                  strokeLinejoin="round"
                />
              </svg>
            ) : (
              <svg
                viewBox="0 0 24 24"
                fill="none"
                stroke="currentColor"
                strokeWidth="1.5"
                className="h-6 w-6"
              >
                <path
                  d="M6 18 18 6M6 6l12 12"
                  strokeLinecap="round"
                  strokeLinejoin="round"
                />
              </svg>
            )}
          </button>

          {/* Logo */}
          <div className="flex items-center gap-6">
            <img
              src="https://tailwindcss.com/plus-assets/img/logos/mark.svg?color=indigo&shade=500"
              className="h-8"
              alt="Logo"
            />

            {/* Desktop Menu */}
            <div className="hidden sm:flex space-x-4">
              {["Dashboard", "Team", "Projects", "Calendar"].map((item) => (
                <a
                  key={item}
                  href="#"
                  className="px-3 py-2 rounded-md text-sm text-gray-300 hover:bg-white/5 hover:text-white"
                >
                  {item}
                </a>
              ))}
            </div>
          </div>

          {/* Right Icon */}
          <button className="p-2 text-gray-400 hover:text-white">
            <svg
              viewBox="0 0 24 24"
              fill="none"
              stroke="currentColor"
              strokeWidth="1.5"
              className="h-6 w-6"
            >
              <path
                d="M14.857 17.082a23.848 23.848 0 0 0 5.454-1.31A8.967 8.967 0 0 1 18 9.75V9A6 6 0 0 0 6 9v.75a8.967 8.967 0 0 1-2.312 6.022c1.733.64 3.56 1.085 5.455 1.31m5.714 0a24.255 24.255 0 0 1-5.714 0m5.714 0a3 3 0 1 1-5.714 0"
                strokeLinecap="round"
                strokeLinejoin="round"
              />
            </svg>
          </button>
        </div>
      </div>

      {/* Mobile Menu */}
      {menuOpen && (
        <div className="sm:hidden bg-gray-800 px-2 pb-3 space-y-1">
          {["Dashboard", "Team", "Projects", "Calendar"].map((item) => (
            <a
              key={item}
              href="#"
              className="block px-3 py-2 rounded-md text-gray-300 hover:bg-white/5 hover:text-white"
            >
              {item}
            </a>
          ))}
        </div>
      )}
    </nav>
  );
}
