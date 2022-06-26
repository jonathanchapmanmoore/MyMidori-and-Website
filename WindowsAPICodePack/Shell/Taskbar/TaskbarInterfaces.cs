//Copyright (c) Microsoft Corporation.  All rights reserved.

using Microsoft.Windows.Shell;
using Microsoft.Windows.Shell.PropertySystem;
namespace Microsoft.Windows.Taskbar
{
    /// <summary>
    /// Interface for jump list items
    /// </summary>
    public interface IJumpListItem
    {
        /// <summary>
        /// Gets or sets this item's path
        /// </summary>
        string Path { get; set; }
    }

    /// <summary>
    /// Interface for jump list tasks
    /// </summary>
    public abstract class JumpListTask
    {
        internal abstract IShellLinkW NativeShellLink { get; }
    }
}
