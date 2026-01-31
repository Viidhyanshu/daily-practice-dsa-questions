"use client";
import React from "react";

export default function Footer() {
  return (
    <div>
      <div className="relative isolate bg-gray-900 px-6 py-24 sm:py-32 lg:px-8">
        <div
          ariaHidden="true"
          className="absolute inset-x-0 -top-3 -z-10 transform-gpu overflow-hidden px-36 blur-3xl"
        >
          <div
            style={{
              clipPath:
                "polygon(74.1% 44.1%, 100% 61.6%, 97.5% 26.9%, 85.5% 0.1%, 80.7% 2%, 72.5% 32.5%, 60.2% 62.4%, 52.4% 68.1%, 47.5% 58.3%, 45.2% 34.5%, 27.5% 76.7%, 0.1% 64.9%, 17.9% 100%, 27.6% 76.8%, 76.1% 97.7%, 74.1% 44.1%)",
            }}
            className="mx-auto aspect-[1155/678] w-[288.75px] bg-gradient-to-tr from-[#ff80b5] to-[#9089fc] opacity-20"
          ></div>
        </div>

        <div className="mx-auto max-w-4xl text-center">
          <h2 className="text-base/7 font-semibold text-indigo-400">
            Pricing
          </h2>
          <p className="mt-2 text-5xl font-semibold tracking-tight text-balance text-white sm:text-6xl">
            Choose the right plan for you
          </p>
        </div>

        <p className="mx-auto mt-6 max-w-2xl text-center text-lg font-medium text-pretty text-gray-400 sm:text-xl/8">
          Choose an affordable plan that’s packed with the best features for
          engaging your audience, creating customer loyalty, and driving sales.
        </p>

        <div className="mx-auto mt-16 grid max-w-lg grid-cols-1 items-center gap-y-6 sm:mt-20 lg:max-w-4xl lg:grid-cols-2">
          {/* Hobby */}
          <div className="rounded-3xl bg-white/5 p-8 ring-1 ring-white/10 sm:p-10">
            <h3 className="text-base/7 font-semibold text-indigo-400">
              Hobby
            </h3>

            <p className="mt-4 flex items-baseline gap-x-2">
              <span className="text-5xl font-semibold tracking-tight text-white">
                $29
              </span>
              <span className="text-base text-gray-400">/month</span>
            </p>

            <ul className="mt-8 space-y-3 text-sm text-gray-300">
              {[
                "25 products",
                "Up to 10,000 subscribers",
                "Advanced analytics",
                "24-hour support response time",
              ].map((item, i) => (
                <li key={i} className="flex gap-x-3">
                  <svg
                    viewBox="0 0 20 20"
                    fill="currentColor"
                    ariaHidden="true"
                    className="h-6 w-5 flex-none text-indigo-400"
                  >
                    <path
                      fillRule="evenodd"
                      clipRule="evenodd"
                      d="M16.704 4.153a.75.75 0 0 1 .143 1.052l-8 10.5a.75.75 0 0 1-1.127.075l-4.5-4.5a.75.75 0 0 1 1.06-1.06l3.894 3.893 7.48-9.817a.75.75 0 0 1 1.05-.143Z"
                    />
                  </svg>
                  {item}
                </li>
              ))}
            </ul>
          </div>

          {/* Enterprise */}
          <div className="relative rounded-3xl bg-gray-800 p-8 ring-1 ring-white/10 sm:p-10">
            <h3 className="text-base/7 font-semibold text-indigo-400">
              Enterprise
            </h3>

            <p className="mt-4 flex items-baseline gap-x-2">
              <span className="text-5xl font-semibold tracking-tight text-white">
                $99
              </span>
              <span className="text-base text-gray-400">/month</span>
            </p>

            <ul className="mt-8 space-y-3 text-sm text-gray-300">
              {[
                "Unlimited products",
                "Unlimited subscribers",
                "Advanced analytics",
                "Dedicated support",
                "Marketing automations",
                "Custom integrations",
              ].map((item, i) => (
                <li key={i} className="flex gap-x-3">
                  <svg
                    viewBox="0 0 20 20"
                    fill="currentColor"
                    ariaHidden="true"
                    className="h-6 w-5 flex-none text-indigo-400"
                  >
                    <path
                      fillRule="evenodd"
                      clipRule="evenodd"
                      d="M16.704 4.153a.75.75 0 0 1 .143 1.052l-8 10.5a.75.75 0 0 1-1.127.075l-4.5-4.5a.75.75 0 0 1 1.06-1.06l3.894 3.893 7.48-9.817a.75.75 0 0 1 1.05-.143Z"
                    />
                  </svg>
                  {item}
                </li>
              ))}
            </ul>
          </div>
        </div>
      </div>
    </div>
  );
}
